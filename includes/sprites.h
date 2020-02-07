/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprites.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/24 10:58:12 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/07 12:33:35 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef SPRITES_H
# define SPRITES_H

#include "cube3d.h"

t_bool	sprites_tab_init(t_map *map, t_mlx *mlx);
t_bool	sprites_init(t_map *map);
void 	sprite_tab_printf(t_map *map);
void	sprite_sort_tab(t_sprite *tab, int size);
t_bool	sprite_get_ray_hits(t_rays r, t_mlx *mlx, int i);
t_bool	sprite_get_dist(t_rays *r, t_mlx *mlx, t_vect v, int i);
void	sprite_get_line_seg(t_sprite *sp, t_mlx *mlx);
void	sprite_ray_create_line(t_rays *r, t_mlx *mlx);
void	sprite_find_mid_ray(t_sprite *sp, t_mlx *mlx);
t_bool 	sprite_draw_column_from_start(t_sprite *sp, t_mlx *mlx, t_rays r);
t_bool	sprite_draw(t_sprite *sp, t_mlx *mlx);
t_bool 	sprite_draw_column_from_end(t_sprite *sp, t_mlx *mlx, t_rays r);


#endif