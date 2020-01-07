/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rays.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 14:23:44 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/07 12:31:24 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef RAYS_H
# define RAYS_H

#include "cube3d.h"

t_bool	rays_tab_init(t_rays *rays, t_mlx *mlx);
t_rays  ray_init(float angle);
t_rays	ray_setup(float angle);
t_bool	rays_cast_all(t_mlx *mlx);
void	rays_printf_tab(t_mlx *mlx, t_rays *ray);
void	rays_printf(t_rays ray);

#endif