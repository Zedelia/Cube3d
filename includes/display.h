/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/08 18:48:29 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 18:48:31 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef display_H
# define display_H

#include "cube3d.h"

t_bool	display_exit_on_click(t_mlx *mlx);
t_bool	display_tile(t_mlx *mlx, t_map *map);

#endif