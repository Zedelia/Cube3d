/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/25 10:50:40 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/17 15:21:28 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

#include "cube3d.h"


typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

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
	t_bool	sprite;
}				t_wall_hit;


typedef struct	s_rays
{
	double		x;
	double		y;
	double		angle;
	double		distance;
	t_fst_hit	hz_fst_inter;
	t_fst_hit	vt_fst_inter;
	t_wall_hit	wall;
	t_bool		facing_up;// N
	t_bool		facing_down; //S
	t_bool		facing_right; // E
	t_bool		facing_left; // W

}				t_rays;





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



typedef struct	s_cam
{
	t_vect	pos;
	int		rotation_angle;
	t_vect	direction;
	t_rays	*ray_tab;
}				t_cam;




typedef struct	s_map
{
	char	*map_file;
	char	*map_char;
	int		**tab;
	int		map_col;
	int		map_lines;
	int		tile;
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
	t_cam		cam;
	t_map		*map;
}				t_mlx;


#endif