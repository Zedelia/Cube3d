/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/09 14:41:23 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/13 18:53:27 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef display_H
# define display_H

#include "cube3d.h"

t_bool	display_exit_on_click(t_mlx *mlx);
t_bool	display_tile(t_mlx *mlx, t_map *map);
void	display_walls(t_mlx *mlx);

void	display_update(t_mlx *mlx);

#endif