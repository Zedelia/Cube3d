/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mlx_s.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/25 11:24:42 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/19 13:44:12 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MLX_S_H
# define MLX_S_H

#include "cube3d.h"

t_bool		mlx_ft_init(t_mlx **mlx, char *file);
void		mlx_free(t_mlx *mlx);


//----------------------

t_bool		img_load_xpm(t_mlx *mlx, char *file, t_img *img);
t_bool		img_display(t_mlx *mlx, t_img *img);
void		image_clear(t_img *image);


#endif