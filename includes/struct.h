/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:21:23 by mbos              #+#    #+#             */
/*   Updated: 2020/03/05 14:32:54 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "cube3d.h"

typedef struct			s_color
{
	int					r;
	int					g;
	int					b;
}						t_color;

typedef struct			s_move
{
	double				x;
	double				y;
	double				r;
	t_bool				vt;
}						t_move;

typedef struct			s_vect
{
	double				x;
	double				y;
}						t_vect;

typedef struct			s_vect_int
{
	int					x;
	int					y;
}						t_vect_int;

typedef struct			s_fromto
{
	int					from;
	int					to;
}						t_fromto;

typedef struct			s_utils
{
	int					y;
	int					color;
	double				dist_inter;
	double				delta;
	double				ratio;
}						t_utils;

/*
** Usefull struct for ray-casting
*/

typedef struct			s_fst_hit
{
	double				x;
	double				y;
	double				dist;
	t_vect				steps;
}						t_fst_hit;

typedef struct			s_wall_hit
{
	t_vect				hz_hit;
	t_vect				vt_hit;
	t_bool				vt;
	t_bool				hz;
}						t_wall_hit;

/*
** Rays structure: to math dist from walls
*/

typedef struct			s_rays
{
	double				x;
	double				y;
	double				angle;
	double				distance;
	double				id;
	t_fst_hit			hz_fst_inter;
	t_fst_hit			vt_fst_inter;
	t_wall_hit			wall;
	t_vect				inter_sprite;
	t_bool				facing_up;
	t_bool				facing_down;
	t_bool				facing_right;
	t_bool				facing_left;

}						t_rays;

/*
** Img structure: save image info in order to display it
*/

typedef struct			s_img
{
	void				*ptr;
	int					*data;
	char				*file;
	int					size_l;
	int					bpp;
	int					endian;
	int					height;
	int					width;
}						t_img;

/*
** Sprite structure: save sprites info to show them if there are visible
*/

typedef struct			s_sprite
{
	int					x;
	int					y;
	t_vect_int			temp_pos;
	t_vect				pos;
	t_img				*img;
	double				dist;
	double				h;
	double				w;
	t_fromto			fty;
	t_fromto			ftx;
	t_vect_int			pixget;
	double				screenx;
	t_vect				tform;
	t_bool				visible;
}						t_sprite;

/*
** Camera structure: save the camera position and the rays tab
*/

typedef struct			s_cam
{
	t_vect				pos;
	int					rotation_angle;
	t_vect				direction;
	t_rays				*ray_tab;
	t_vect				plan;
}						t_cam;

/*
** Map parse structure: structure used only to parse the map properly
*/

typedef struct			s_maparse
{
	char				*line;
	int					columns;
	int					id;
	int					sp;
	struct s_maparse	*next;
}						t_maparse;

/*
** Map structure: all the map info
*/

typedef struct			s_map
{
	char				*map_file;
	int					**tab;
	t_sprite			*sprite_tab;
	t_maparse			*lines;
	int					nb_sprites;
	int					nb_col;
	int					nb_lines;
	int					tile;
	int					w;
	int					h;
	int					sky;
	int					floor;
	t_img				life;
	t_img				frame;
	t_img				north;
	t_img				south;
	t_img				west;
	t_img				east;
	t_img				sprite;
	t_img				sp1;
	t_img				sp2;
	t_img				sp3;
}						t_map;

/*
** Mlx structure: the main struct
*/

typedef struct			s_mlx
{
	void				*ptr;
	void				*win;
	t_img				img;
	t_cam				cam;
	t_map				*map;
	t_bool				bonus1;
	t_bool				bonus2;
}						t_mlx;

#endif
