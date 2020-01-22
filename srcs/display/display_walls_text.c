/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_walls_text.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/20 19:09:41 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 14:10:26 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	display_wall_col_hz(t_rays r, t_map *map, t_img img, t_mlx *mlx)
{
	int y;
	t_vect 	top_bot;
	t_vect	set;

	set.x = (r.wall.hz_hit.x - (int)r.wall.hz_hit.x) * img.width;
	set.x = ft_abs(set.x);
	top_bot.x = map->r_height * 0.5 - map->r_height / r.distance * 0.5;
	top_bot.y = map->r_height * 0.5 + map->r_height / r.distance * 0.5;
	if (r.distance == 0 || (top_bot.x - top_bot.y) == 0)
		return (return_false(__func__, "[FAIL] can't divide by 0"));
	y = top_bot.x;
	display_roof(mlx, r.x_id, top_bot.x);
	while (y < top_bot.y)
	{
		set.y = (y - top_bot.x) * ((double)img.height / (top_bot.y - top_bot.x));
		ft_pixel_put(mlx, r.x_id, y, check_color(img, set, r.facing_up));
		y++;
	}
	display_floor(mlx, r.x_id, top_bot.y);
	return (True);
}

t_bool	 display_wall_col_vt(t_rays r, t_map *map, t_img img, t_mlx *mlx)
{
	int		y;
	t_vect 	top_bot;
	t_vect	set;

	set.x = ((r.wall.vt_hit.y - (int)r.wall.vt_hit.y) * img.width);
	while ((set.x = ft_abs(set.x)) > img.width)
		set.x = img.height - set.x;
	top_bot.x = map->r_height * 0.5 - map->r_height / r.distance * 0.5;
	top_bot.y = map->r_height * 0.5 + map->r_height / r.distance * 0.5;
	if (r.distance == 0 || (top_bot.x - top_bot.y) == 0)
		return (return_false(__func__, "[FAIL] can't divide by 0"));
	y = top_bot.x;
	display_roof(mlx, r.x_id, top_bot.x);
	while (y < top_bot.y)
	{
		set.y = (y - top_bot.x) * ((double)img.height / (top_bot.y - top_bot.x));
		ft_pixel_put(mlx, r.x_id, y, check_color(img, set, r.facing_up));
		y++;
	}
	display_floor(mlx, r.x_id, top_bot.y);
	return (True);
}
