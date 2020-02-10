/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cube3d.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/22 15:29:00 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 18:28:13 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "../lib/minilibx_opengl/mlx.h"
# include "../lib/Printf/includes/ft_printf.h"
# include "../lib/Printf/libft/includes/libft.h"

# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <sys/stat.h>
# include <stdint.h>

# define WIN_WIDTH 2560
# define WIN_HEIGHT 1440
# define FOV_DEGREE 60.0
# define TURN_SPEED 6
# define WALK_SPEED 1
# define MINI_MAP_SCALE 4

# define MAP_INFOS "RNsWESFC"
# define MAP_INPUTS "01NSEW"
# define SPRITES "2345"

# define ROOF_COLOR 0x0F52BA
# define FLOOR_COLOR 0xFF007F

# define DIST_MAX 20.00
# define BLACK 0x000000

# define _XPIXELPERMETER 0xEC4
# define _YPIXELPERMETER 0xEC4
# define DPI 72

# include "struct.h"
# include "mlx_s.h"
# include "display.h"
# include "rays.h"
# include "utils_c3d.h"
# include "map.h"
# include "keys.h"
# include "sprites.h"

typedef unsigned long long	t_uintmax;
typedef unsigned char		t_uchar;

#endif
