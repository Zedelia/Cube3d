/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   move.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/08 19:46:00 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/09 10:36:34 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#ifndef MOVE_H
# define MOVE_H

#include "cube3d.h"

int		move_keydown(int key, t_mlx *mlx);
t_bool	move_apply(t_move *move, t_mlx *mlx);

#endif