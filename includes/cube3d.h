/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cube3d.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/22 15:29:00 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/09 12:02:33 by mbos        ###    #+. /#+    ###.fr     */
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
# include <string.h>


# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define FOV_DEGREE 60.0
# define TURN_SPEED 0.3000000
# define WALK_SPEED 0.3000000
# define MAP_INFOS "RNsWESFC"

// # ifndef BUFFER_SIZE
// #  define BUFFER_SIZE 8
// # endif

typedef unsigned long long	t_uintmax;
typedef unsigned char		t_uchar;

# include "struct.h"
# include "mlx_s.h"
# include "display.h"
# include "rays.h"
# include "utils_c3d.h"
# include "map.h"
# include "camera.h"
# include "move.h"
# include "keys.h"

#endif