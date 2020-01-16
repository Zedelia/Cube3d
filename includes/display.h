/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/09 14:41:23 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/16 18:17:50 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef display_H
# define display_H

#include "cube3d.h"

t_bool	display_exit_on_click(t_mlx *mlx);
t_bool	display_tile(t_mlx *mlx, t_map *map);
t_bool	display_walls(t_mlx *mlx);
t_bool	display_rays(t_mlx *mlx, t_rays *r);

void	display_update(t_mlx *mlx);

#endif