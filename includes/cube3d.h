/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cube3d.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/22 15:29:00 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/27 19:04:03 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/minilibx_opengl/mlx.h"
# include "../lib/Printf/includes/ft_printf.h"
# include "../lib/Printf/libft/includes/libft.h"

# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define FOV_DEG 60.0
# define MAP_INFOS "RNsWESFC"

// # ifndef BUFFER_SIZE
// #  define BUFFER_SIZE 8
// # endif

typedef unsigned long long	t_uintmax;
typedef unsigned char		t_uchar;


# include "struct.h"
# include "mlx_s.h"
# include "img.h"
# include "display.h"
# include "rays.h"
# include "cube3d_utils.h"
# include "map.h"

#endif