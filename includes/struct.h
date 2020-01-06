/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/25 10:50:40 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/04 16:26:12 by mbos        ###    #+. /#+    ###.fr     */
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
	int		nb_rays;
	t_vect	direction;
	float	rotation_angle;
	int		turn_direction; // -1 for left, +1 for right
	int		walk_direction; // -1 for back, +1 for front
	float	walk_speed;
	float	turn_speed;
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
	int		texture_hit;
	float	angle;
	float	distance;
	t_bool	facing_left;
	t_bool	facing_right;

}				t_rays;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

#endif