/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   img.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/25 11:28:07 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/25 15:27:56 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef IMG_H
# define IMG_H

#include "cube3d.h"

t_bool		img_load_xpm(t_mlx *mlx, char *file, t_img *img);
t_bool	img_display(t_mlx *mlx, t_img *img);


#endif