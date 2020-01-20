/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_walls_text.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/20 19:09:41 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 19:10:12 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	display_wall_hz(t_rays r, t_map *map, t_img img, t_mlx *mlx, int x)
{
	int y;
	double bottom;
	double top;
	double offset_x;
	double	offset_y;

	offset_x = (r.wall.hz_hit.x - (int)r.wall.hz_hit.x) * img.width;
	offset_x = ft_abs(offset_x);
	top = map->r_height * 0.5 - map->r_height / r.distance * 0.5;
	bottom = map->r_height * 0.5 + map->r_height / r.distance * 0.5;
	y = top;
	while (y < bottom)
	{
		offset_y = (y - top) * ((double)img.height / (bottom - top));
		ft_pixel_put(mlx, x, y, ft_pixel_get_color(img, offset_x, offset_y));
		y++;
	}
	return (True);
}

t_bool	 display_wall_vt(t_rays r, t_map *map, t_img img, t_mlx *mlx, int x)
{
	int y;
	double	bottom;
	double	top;
	// TODO ici remplacer les offset par un vect
	double 	offset_x;
	double	offset_y;

// TODO r.distance != 0 => error
// bottom - top != 0 => error
	offset_x = ((r.wall.vt_hit.y - (int)r.wall.vt_hit.y) * img.width);
	while ((offset_x = ft_abs(offset_x)) > img.width)
		offset_x = img.height - offset_x;
	top = map->r_height * 0.5 - map->r_height / r.distance * 0.5;
	bottom = map->r_height * 0.5 + map->r_height / r.distance * 0.5;
	y = top;
	// TODO ajouter impression ciel de -1 > top
	while (y < bottom)
	{
		offset_y = (y - top) * ((double)img.height / (bottom - top));
		ft_pixel_put(mlx, x, y,ft_pixel_get_color(img, offset_x, offset_y));
		y++;
	}
	// TODO ajouter impression ciel de bottom > height
	return (True);
}
