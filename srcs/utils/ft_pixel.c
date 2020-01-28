/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pixel.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/28 11:27:35 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/28 11:28:16 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	ft_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	if (x >= mlx->map->r_width || y >= mlx->map->r_height || x < 0 || y < 0)
		return ;
	mlx->img.data[y * mlx->map->r_width + x] = color;
}

int		ft_pixel_get_color(t_img img, int x, int y)
{
	int color;

	if (x >= img.width || y >= img.height || x < 0 || y < 0)
		return (-1);
	color = img.data[y * img.width + x];
	return (color);
}

// TODO METTRE EN PLACE ceci en changeant les variables de display_walls

// int check_color(t_img img, int x, int y, t_bool up? )
// {
// 	int color;

// 	if ((color = ft_pixel_get_color(img, x, y)) == -1)
// 	{
// 		if (up? )
// 			return (couleurduciel);
// 		return (couleurdusol);
// 	}
// 	return (color);
// }