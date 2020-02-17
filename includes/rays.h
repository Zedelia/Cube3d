/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:21:13 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 13:21:14 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYS_H
# define RAYS_H

# include "cube3d.h"

/*
** Init rays tab and ray
*/

t_bool	rays_tab_init(t_mlx *mlx);
t_rays	ray_init(double angle, t_vect pos);

/*
** Ray casting
*/

t_bool	rays_casting(t_mlx *mlx);
t_bool	ray_get_distance(t_rays *r, t_mlx *mlx);
t_bool	ray_get_intersections(t_rays *r, t_mlx *mlx);
t_bool	ray_get_steps(t_rays *r, t_mlx *mx);
t_bool	ray_get_walls_hit(t_rays *r, t_mlx *mlx);
t_bool	ray_hits_vt_wall_at(t_rays *r, t_vect v, t_mlx *mlx);
t_bool	ray_hits_hz_wall_at(t_rays *r, t_vect v, t_mlx *mlx);

/*
** Utils
*/

void	ray_get_direction(t_rays *ray);
t_bool	ray_rotate(t_rays *r, float angle);

#endif
