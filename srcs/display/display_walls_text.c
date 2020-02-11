/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_walls_text.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/20 19:09:41 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/11 17:28:37 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	display_wall_hz(t_rays r, t_img img, t_mlx *mlx, int x)
{
	int			i;
	t_fromto	y;
	t_vect		offset;
	int			color;

	offset.x = ft_abs((r.wall.hz_hit.x - (int)r.wall.hz_hit.x) * img.width);
	y.from = mlx->map->r_height * 0.5 - mlx->map->r_height / r.distance * 0.5;
	y.to = mlx->map->r_height * 0.5 + mlx->map->r_height / r.distance * 0.5;
	if (r.distance == 0 || y.to - y.from == 0)
		return (return_false(__func__, "[FAIL] can't divide by 0", mlx));
	i = y.from;
	while (i < y.to)
	{
		offset.y = (i - y.from) * ((double)img.height / (y.to - y.from));
		if ((color = get_correct_color(img, mlx, offset, i)) != -1)
			pixel_put(mlx, x, i,
					shade_color(color,
					r.distance > DIST_MAX ? 1 : r.distance / DIST_MAX));
		i++;
	}
	return (True);
}

t_bool	display_wall_vt(t_rays r, t_img img, t_mlx *mlx, int x)
{
	int			i;
	t_fromto	y;
	t_vect		offset;
	int			color;

	offset.x = ((r.wall.vt_hit.y - (int)r.wall.vt_hit.y) * img.width);
	while ((offset.x = ft_abs(offset.x)) > img.width)
		offset.x = img.height - offset.x;
	y.from = mlx->map->r_height * 0.5 - mlx->map->r_height / r.distance * 0.5;
	y.to = mlx->map->r_height * 0.5 + mlx->map->r_height / r.distance * 0.5;
	if (r.distance == 0 || y.to - y.from == 0)
		return (return_false(__func__, "[FAIL] can't divide by 0", mlx));
	i = y.from;
	while (i < y.to)
	{
		offset.y = (i - y.from) * ((double)img.height / (y.to - y.from));
		if ((color = get_correct_color(img, mlx, offset, i)) != -1)
			pixel_put(mlx, x, i,
					shade_color(color,
					r.distance > DIST_MAX ? 1 : r.distance / DIST_MAX));
		i++;
	}
	return (True);
}
