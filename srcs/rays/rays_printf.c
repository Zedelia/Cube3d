/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rays_printf.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/06 18:40:18 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 17:07:04 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

// REVIEW attention au printf a supprimer

void	rays_printf(t_rays ray)
{
	printf("\n\n>>>> RAY :\n");
	printf("x : %f\n", ray.x);
	printf("y : %f\n", ray.y);
	printf("Vecteur((%f,%f))\n",ray.x,ray.y);
	printf("hz wall-hit-x : %f\n", ray.wall.hz_hit.x);
	printf("hz wall-hit-y : %f\n", ray.wall.hz_hit.y);
	printf("vt wall-hit-x : %f\n", ray.wall.vt_hit.x);
	printf("vt wall-hit-y : %f\n", ray.wall.vt_hit.y);
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
	(void)mlx;
	i = 0;
	while (i < 6)
	{
		rays_printf(ray[i]);
		i++;
	}
}