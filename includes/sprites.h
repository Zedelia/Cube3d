/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:21:18 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 13:21:19 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITES_H
# define SPRITES_H

# include "cube3d.h"

t_bool		sprites_tab_init(t_map *map, t_mlx *mlx);
t_bool		sprites_init(t_map *map);
void		sprite_sort_tab(t_sprite *tab, int size);

/*
** Functions to get all the sprites information
*/

t_bool		sprite_get_ray_hits(t_rays r, t_mlx *mlx, int i);
t_bool		sprite_get_dist(t_rays *r, t_mlx *mlx, t_vect v, int i);
void		sprite_get_line_seg(t_sprite *sp, t_mlx *mlx);
void		sprite_find_mid_ray(t_sprite *sp, t_mlx *mlx);

/*
** Draw all the sprites
*/

t_bool		sprite_draw(t_sprite *sp, t_mlx *mlx);
t_bool		sprite_draw_column_from_start(t_sprite *sp, t_mlx *mlx, t_rays r);
t_bool		sprite_draw_column_from_end(t_sprite *sp, t_mlx *mlx, t_rays r);

/*
** Utils
*/

t_bool		is_inter_in_seg(t_vect inter, t_sprite *sp);
t_vect		line_inter_line(t_line l1, t_line l2);

#endif
