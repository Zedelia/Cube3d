/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprite.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/21 18:03:11 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 19:13:02 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

#include "cube3d.h"

t_bool		sprites_init(t_rays *rays, t_pos pos, t_mlx *mlx);
t_bool		sprites_free(t_rays *rays);
t_bool		sprites_free_all(t_mlx *mlx);

#endif