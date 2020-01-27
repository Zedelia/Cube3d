/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_sprite.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/20 15:01:55 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/27 19:34:57 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

// ca devrait beaucoup changer ici

t_vect		line_inter_line(t_line l1, t_line l2)
{
	float	tmp;
	t_vect	result;

	result.y = 0;
	result.x = 0;
	if (!(tmp = l1.a * l2.b - l2.a * l1.b))
		return (result);
	tmp = 1. / tmp;
	result.x = (l1.b * l2.c - l2.b * l1.c) * tmp;
	result.y = (l1.c * l2.a - l2.c * l1.a) * tmp;
	return (result);
}

t_bool	is_inter_in_seg(t_vect inter, t_sprite *sp)
{
	return (((inter.x <= sp->p2.x && inter.x >= sp->p1.x) 		\
				|| (inter.x <= sp->p1.x && inter.x >= sp->p2.x)) 	\
			&& ((inter.y <= sp->p2.y && inter.y >= sp->p1.y) 		\
				|| (inter.y <= sp->p1.y && inter.y >= sp->p2.y)));
}

void	sprite_ray_create_line(t_rays *r, t_mlx *mlx)
{
	r->line_eq.a = r->y;
	r->line_eq.b = -r->x;
	r->line_eq.c = r->x * (mlx->cam.pos.y + 0.5) - r->y * (mlx->cam.pos.x + 0.5);
}

// TODO initialisation des var

void	math_mid_ray(t_sprite *sp, t_mlx *mlx)
{
	t_rays mid_r;

	mid_r.x = mlx->cam.pos.x - sp->x;
	mid_r.y = mlx->cam.pos.y - sp->y;
	sp->mid_ray = mid_r;
}

t_vect 	norm_vect(t_vect v)
{
	t_vect v_norm;
	double v_size;

	v_size = sqrt(v.y * v.y + v.x * v.x);
	v_norm.x = v.x / v_size;
	v_norm.y = v.y / v_size;
	return (v_norm);
}

void	sprite_get_line_seg(t_sprite *sp, t_mlx *mlx)
{
	t_rays line_ray;

	math_mid_ray(sp, mlx);
	line_ray.x = sp->mid_ray.x;
	line_ray.y = sp->mid_ray.y;
	ray_rotate(&line_ray, 90);
	sp->line_vect.x = line_ray.x;
	sp->line_vect.y = line_ray.y;
	sp->line_eq.a = line_ray.y;
	sp->line_eq.b = -line_ray.x;
	sp->line_eq.c = line_ray.x * (sp->y + 0.5) - line_ray.y * (sp->x + 0.5);
	sp->line_norm_v = norm_vect(sp->line_vect);
	sp->p1.x = sp->x + 0.5 + sp->line_norm_v.x * 0.5;
	sp->p1.y = sp->y + 0.5 + sp->line_norm_v.y * 0.5;
	sp->p2.x = sp->x + 0.5 - sp->line_norm_v.x * 0.5;
	sp->p2.y = sp->y + 0.5 - sp->line_norm_v.y * 0.5;
}

t_bool 	draws_sprite_column(t_vect inter, t_sprite *sp, t_mlx *mlx, t_rays r)
{
	// t_vect	inter_norm;
	// double	inter_size;
	double	d_inter;
	int y;
	t_fromto scrn_y;
	(void)sp;
	(void)inter;
// dist entre inter et position
//	r_height / dist
	// inter_norm = norm_vect(inter);
	// d_inter = dist_correct_fish_eye(*r, mlx, ft_math_dist(inter.x, inter.y, mlx));

	d_inter = sqrt((sp->mid_ray.x) * (sp->mid_ray.x) + (sp->mid_ray.y) * (sp->mid_ray.y));
	scrn_y.from = mlx->map->r_height * 0.5 - mlx->map->r_height / d_inter * 0.5;
	scrn_y.to = mlx->map->r_height * 0.5 + mlx->map->r_height / d_inter * 0.5;
	printf("%f\n", d_inter);
	y = scrn_y.from;
	while (y < scrn_y.to)
	{
		// offset_y = (y - top) * ((double)img.height / (bottom - top));
		ft_pixel_put(mlx, r.id, y, 0x000000);
		y++;
	}
	return (True);




}

t_bool	draw_sprite(t_sprite *sp, t_mlx *mlx)
{
	t_vect	inter;
	int i;

	sprite_get_line_seg(sp, mlx);
	i = sp->r_before.id;
	while (i < sp->r_after.id)
	{
		sprite_ray_create_line(&mlx->cam.ray_tab[i], mlx);
		inter = line_inter_line(sp->line_eq, mlx->cam.ray_tab[i].line_eq);
		if (is_inter_in_seg(inter, sp) == True)
		{
			draws_sprite_column(inter, sp, mlx, mlx->cam.ray_tab[i]);}
		i++;
	}

	return (True);
}

t_bool	display_sprite(t_mlx *mlx)
{
	int i;

	i = 0;
	sprite_sort_tab(mlx->map->sprite_tab, mlx->map->map_sprites);
	while (i < mlx->map->map_sprites)
	{
		if (mlx->map->sprite_tab[i].visible == 1)
			draw_sprite(&mlx->map->sprite_tab[i], mlx);
		i++;
	}

	return (True);
}



	// int 		color;
	// double 		sp_height;
	// t_fromto 	x;
	// t_fromto 	y;
	// t_vect_int 	pixput;
	// t_vect 	pixget;
	// int 	start;
	// double 	end;


	// sp_height = mlx->map->r_height / sp->dist;
	// x.from = sp->r_before.id ;
	// x.to = sp->r_after.id + 1;
	// y.from = mlx->map->r_height * 0.5 - sp_height * 0.5;
	// y.to = mlx->map->r_height * 0.5 + sp_height * 0.5;
	// pixput.y = y.from;
	// pixput.x = x.from;

	// start = (sp->r_before.id == 0) ? (sp->r_after.id - sp->r_before.id)  : 0;
	// while (pixput.y < y.to)
	// {
	// 	pixput.x = x.from ;
	// 	pixget.y = (pixput.y - y.from) * mlx->map->r_width/ (y.to - y.from);
	// 	pixget.x = start;
	// 	while (start < sp_height)
	// 	{
	// 		pixget.x += 10;
	// 		if((color = ft_pixel_get_color(img, pixget.x, pixget.y)) >= 0)
	// 			ft_pixel_put(mlx, pixput.x, pixput.y, color);
	// 		start++;
	// 		pixput.x++;
	// 	}
	// 	pixput.y++;
	// 	pixget.y++;
	// }