/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rays.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 14:23:44 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/07 17:40:37 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef RAYS_H
# define RAYS_H

#include "cube3d.h"

void	rays_printf_tab(t_mlx *mlx, t_rays *ray);
void	rays_printf(t_rays ray);
void	ray_init_directions(t_rays *ray);
t_bool	rays_tab_init(t_mlx *mlx);
t_rays  ray_init(float angle);
t_rays	ray_setup(float angle);
t_bool	rays_casting(t_mlx *mlx);
t_bool	ray_rotate(t_rays *r, t_mlx *mlx);
t_bool	rays_parser(t_mlx *mlx);
t_bool	ray_get_distance(t_rays *r, t_mlx *mlx);
float	rays_closest_hit_y(t_rays *ray, t_mlx *mlx);
float	rays_closest_hit_x(t_rays *ray, t_mlx *mlx);
		ray_get_horizontal_intersection(t_rays *r, t_mlx *mlx)

#endif