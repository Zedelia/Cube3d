/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/25 10:50:40 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/02 21:32:39 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

#include "cube3d.h"

// typedef struct s_rays	t_rays;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_line
{
	double			a;
	double			b;
	double			c;
}				t_line;

typedef struct	s_move
{
	double		x;
	double		y;
	double		r;
	t_bool		vt;
}				t_move;

typedef struct	s_vect
{
	double	x;
	double	y;
}				t_vect;

typedef struct	s_vect_int
{
	int	x;
	int	y;
}				t_vect_int;

typedef struct	s_fromto
{
	int	from;
	int	to;
}				t_fromto;

typedef struct	s_utils
{
	int		y;
	int		color;
	double 	dist_inter;
	double	delta;
}				t_utils;



typedef struct	s_fst_hit
{
	double	x;
	double	y;
	double	dist;
	t_vect	steps;
}				t_fst_hit;

typedef struct	s_wall_hit
{
	t_vect	hz_hit;
	t_vect	vt_hit;
	t_bool	vt;
	t_bool	hz;
}				t_wall_hit;


typedef struct	s_rays
{
	double		x;
	double		y;
	double		angle;
	double		distance;
	double			id;
	t_fst_hit	hz_fst_inter;
	t_fst_hit	vt_fst_inter;
	t_wall_hit	wall;
	t_line		line_eq;
	t_vect		inter_sprite;
	t_bool		facing_up;// N
	t_bool		facing_down; //S
	t_bool		facing_right; // E
	t_bool		facing_left; // W

}				t_rays;

typedef struct	s_sprite
{
	int		x;
	int		y;
	double	dist;
	double	img_w;
	double	start;
	t_rays 	mid_ray;
	t_vect	line_vect;
	t_line	line_eq;
	t_vect	line_norm_v;
	t_vect	p1;
	t_vect  p2;
	t_rays  r_fst_hit;
	t_rays	r_last_hit;
	t_rays  r_before;
	t_rays	r_after;
	int		fst_ray_print;
	int		last_ray_print;
	t_bool	visible;
}				t_sprite;

typedef struct	s_img
{
	void		*ptr;
	int			*data;
	char		*file;
	int			size_l;
	int			bpp;
    int         endian;
    int         height;
    int         width;
}				t_img;



typedef struct	s_cam
{
	t_vect		pos;
	int			rotation_angle;
	t_vect		direction;
	t_rays		*ray_tab;
}				t_cam;


typedef struct	s_map
{
	char		*map_file;
	char		*map_char;
	int			**tab;
	t_sprite	*sprite_tab;
	int			map_sprites;
	int			map_col;
	int			map_lines;
	int			tile;
	int			r_width;
	int			r_height;
	int			cell;
	int			floor;
	t_img		north;
	t_img		south;
	t_img		west;
	t_img		east;
	t_img		sprite;
}				t_map;



typedef struct	s_mlx
{
	void		*ptr;
	void		*win;
	t_img		img;
	t_cam		cam;
	t_map		*map;
}				t_mlx;

#endif