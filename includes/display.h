/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/17 13:20:48 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/23 14:23:59 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
#ifndef DISPLAY_H
# define DISPLAY_H

# include "cube3d.h"

/*
** Display update at each movement
*/

void		display_update(t_mlx *mlx);

/*
** Display minimap
*/

t_bool		display_mini_map(t_mlx *mlx, t_map *map);
t_bool		display_rays(t_mlx *mlx, t_rays *r);

/*
** Display walls
*/

t_bool		display_walls(t_mlx *mlx);
t_bool		display_textured_walls(t_mlx *mlx);
t_bool		display_wall_hz(t_rays r, t_img img, t_mlx *mlx, int x);
t_bool		display_wall_vt(t_rays r, t_img img, t_mlx *mlx, int x);

/*
** Display sprites
*/

t_bool		display_sprite(t_mlx *mlx);

/*
** Display sky_floor
*/

t_bool		display_sky(t_mlx *mlx);
t_bool		display_floor(t_mlx *mlx);

/*
** Others
*/
void		display_bonus(t_mlx *mlx, t_img img);
int			display_exit(void *mlx);
t_bool		display_exit_on_click(t_mlx *mlx);

#endif
