/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/25 10:50:40 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 18:23:12 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
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

typedef struct			s_line
{
	double				a;
	double				b;
	double				c;
}						t_line;

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
	t_line				line_eq;
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
	t_img				*img;
	double				dist;
	double				start;
	t_vect				line_vect;
	t_line				line_eq;
	t_vect				line_norm_v;
	t_vect				p1;
	t_vect				p2;
	t_rays				mid_ray;
	t_rays				r_fst_hit;
	t_rays				r_last_hit;
	t_rays				r_before;
	t_rays				r_after;
	int					fst_ray_print;
	int					last_ray_print;
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
	int					r_width;
	int					r_height;
	int					cell;
	int					floor;
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
	t_img				health;
}						t_mlx;

#endif
