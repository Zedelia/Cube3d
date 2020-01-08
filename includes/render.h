/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   render.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/08 18:48:29 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 18:48:31 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef render_H
# define render_H

#include "cube3d.h"

t_bool	render_exit_on_click(t_mlx *mlx);
t_bool	render_tile(t_mlx *mlx, t_map *map);

#endif