/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprites.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/24 10:58:12 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/24 11:08:11 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef SPRITES_H
# define SPRITES_H

#include "cube3d.h"

t_bool				sprites_tab_init(t_map *map);
t_bool				sprites_init(t_map *map);
void 				sprite_tab_printf(t_map *map);
t_bool				sprite_get_ray_hits(t_rays r, t_mlx *mlx, t_vect v, int i);
t_bool				sprite_get_dist(t_rays *r, t_mlx *mlx, t_vect v, int i);

#endif