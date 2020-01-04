/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/25 10:50:40 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/04 13:37:35 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

#include "cube3d.h"

/*
** MLX and IMG management
*/
typedef struct	s_img
{
	void		*ptr;
	int			*data;
	int			size_l;
	int			bpp;
    int         endian;
    int         height;
    int         width;
}				t_img;

typedef struct	s_vect
{
	float	x;
	float	y;
}				t_vect;
typedef struct	s_camera
{
	float	pos_x;
	float	pos_y;
	t_vect	direction;
	float	rotation_angle;
	int		turn_direction;
	int		walk_direction;
}				t_camera;

typedef struct	s_map
{
	char	*map_file;
	char	*map_char;
	int		**tab;
	int		map_col;
	int		map_lines;
	int		r_width;
	int		r_height;
	int		cell;
	int		floor;
	char	*text_north;
	char	*text_south;
	char	*text_west;
	char	*text_east;
	char	*text_sprite;
}				t_map;

typedef struct	s_mlx
{
	void		*ptr;
	void		*win;
	t_img		img;
	t_camera	camera;
	t_map		*map;
}				t_mlx;

typedef struct	s_rays
{
	float	x;
	float	y;
	float	ox;
	float	oy;
}				t_rays;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

#endif