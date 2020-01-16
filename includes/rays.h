/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rays.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 14:23:44 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/16 16:24:47 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef RAYS_H
# define RAYS_H

#include "cube3d.h"

void	rays_printf_tab(t_mlx *mlx, t_rays *ray);
void	rays_printf(t_rays ray);
void	ray_get_direction(t_rays *ray);
t_bool	rays_tab_init(t_mlx *mlx);
t_bool	rays_casting(t_mlx *mlx);
t_rays  ray_init(double angle, t_vect pos);
t_rays	ray_setup(double angle);
t_bool	ray_rotate(t_rays *r, t_mlx *mlx);
t_bool	ray_get_distance(t_rays *r, t_mlx *mlx);
t_bool	ray_get_intersections(t_rays *r, t_mlx *mlx);
t_bool 	ray_get_steps(t_rays *r, t_mlx *mx);
t_bool	ray_get_walls_hit(t_rays *r, t_mlx * mlx);
t_bool	ray_hits_vt_wall_at(t_rays *r, t_vect v, t_mlx *mlx);
t_bool	ray_hits_hz_wall_at(t_rays *r, t_vect v, t_mlx *mlx);

#endif