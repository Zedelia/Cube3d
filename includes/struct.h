/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/25 10:50:40 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 18:54:12 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

#include "cube3d.h"

typedef enum
{
	left = -1,
	right = 1,
}			t_turn_direction;

typedef enum
{
	front = 1,
	back = -1,
}			t_walk_direction;
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
}			t_vect;

typedef struct	s_camera
{
	float	pos_x;
	float	pos_y;
	float	rotation_angle;
	t_vect	direction;
	t_rays	ray_tab;
	int		s_tile;
	int		turn_direction; // -1 for left, +1 for right
	int		walk_direction; // -1 for back, +1 for front
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
	float	wall_hit_x;
	float	wall_hit_y;
	float	angle;
	float	distance;
	t_bool	facing_up;
	t_bool	facing_down;
	t_bool	facing_right;
	t_bool	facing_left;

}				t_rays;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

#endif