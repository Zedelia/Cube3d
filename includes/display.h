/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/09 14:41:23 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/19 16:06:13 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef display_H
# define display_H

#include "cube3d.h"

t_bool	display_exit_on_click(t_mlx *mlx);
t_bool	display_mini_map(t_mlx *mlx, t_map *map);
t_bool	display_walls(t_mlx *mlx);
t_bool	display_rays(t_mlx *mlx, t_rays *r);
int		display_get_text_color_hz(t_img *img, t_rays r, t_mlx *mlx);
void	display_update(t_mlx *mlx);
t_bool	 display_textured_walls(t_mlx *mlx);
t_bool		display_roof(t_mlx *mlx);
t_bool		display_floor(t_mlx *mlx);

#endif