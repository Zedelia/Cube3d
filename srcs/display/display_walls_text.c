/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_walls_text.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/20 19:09:41 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/29 17:37:24 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	display_wall_hz(t_rays r, t_map *map, t_img img, t_mlx *mlx, int x)
{
	int 	y;
	double	bottom;
	double	top;
	t_vect	offset;


	offset.x = (r.wall.hz_hit.x - (int)r.wall.hz_hit.x) * img.width;
	offset.x = ft_abs(offset.x);
	top = map->r_height * 0.5 - map->r_height / r.distance * 0.5;
	bottom = map->r_height * 0.5 + map->r_height / r.distance * 0.5;
	if (r.distance == 0 || bottom - top == 0)
		return (return_false(__func__, "[FAIL] can't divide by 0"));
	y = top;
	while (y < bottom)
	{
		offset.y = (y - top) * ((double)img.height / (bottom - top));
		ft_pixel_put(mlx, x, y, shade_color(ft_pixel_get_color(img, offset.x, offset.y), r.distance > DIST_MAX ? 1 : r.distance / DIST_MAX));
		y++;
	}
	return (True);
}

t_bool	 display_wall_vt(t_rays r, t_map *map, t_img img, t_mlx *mlx, int x)
{
	int 	y;
	double	bottom;
	double	top;
	t_vect	offset;

	offset.x = ((r.wall.vt_hit.y - (int)r.wall.vt_hit.y) * img.width);
	while ((offset.x = ft_abs(offset.x)) > img.width)
		offset.x = img.height - offset.x;
	top = map->r_height * 0.5 - map->r_height / r.distance * 0.5;
	bottom = map->r_height * 0.5 + map->r_height / r.distance * 0.5;
	if (r.distance == 0 || bottom - top == 0)
		return (return_false(__func__, "[FAIL] can't divide by 0"));
	y = top;
	while (y < bottom)
	{
		offset.y = (y - top) * ((double)img.height / (bottom - top));
		get_right_color(img, r.id, y, r.facing_up);
		ft_pixel_put(mlx, x, y, 											\
				shade_color(ft_pixel_get_color(img, offset.x, offset.y), 	\
				r.distance > DIST_MAX ? 1 : r.distance / DIST_MAX));
		y++;
	}
	return (True);
}


