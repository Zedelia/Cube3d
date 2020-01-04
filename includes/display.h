/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/25 15:34:56 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/03 18:15:32 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

#include "cube3d.h"

t_bool	display_exit_on_click(t_mlx *mlx);
t_bool	display_tile(t_mlx *mlx, t_map *map);

#endif