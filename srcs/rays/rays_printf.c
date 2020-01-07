/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rays_printf.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/06 18:40:18 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/07 15:25:07 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

// attention au printf a supprimer

void	rays_printf(t_rays ray)
{
	printf("\n\n>>>> RAY :\n");
	printf("x : %f\n", ray.x);
	printf("y : %f\n", ray.y);
	printf("wall-hit-x : %f\n", ray.wall_hit_x);
	printf("wall-hit-y : %f\n", ray.wall_hit_y);
	printf("angle : %f\n", ray.angle);
	printf("distance : %f\n", ray.distance);
	if (ray.facing_left)
		ft_printf("FACING LEFT ");
	if (ray.facing_right)
		ft_printf("FACING RIGHT ");
	if (ray.facing_down)
		ft_printf("DOWN\n");
	if (ray.facing_up)
		ft_printf("UP\n");
}

void	rays_printf_tab(t_mlx *mlx, t_rays *ray)
{
	int i;

	i = mlx->map->r_width- 1;
	while (i > mlx->map->r_width - 6)
	{
		rays_printf(ray[i]);
		i--;
	}
}