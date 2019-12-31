/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/25 10:50:40 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/31 11:07:34 by mbos        ###    #+. /#+    ###.fr     */
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

typedef struct	s_mlx
{
	void		*ptr;
	void		*win;
	t_img		img;
}				t_mlx;

/*
** Field of view and camera
*/

typedef struct	s_vect
{
	double	x;
	double	y;
}				t_vect;

typedef struct	s_rays
{
	double	x;
	double	y;
	double	ox;
	double	oy;
}				t_rays;

typedef struct	s_camera
{
	double pos_x;
	double pos_y;
	double angle;

	//direction
	//FOV
}				t_camera;

/*
** Map management
*/
typedef struct	s_map
{
	char	*map_file;
	char	*line_map;
	int		**map_tab;
	int		r_width;
	int		r_height;
	int		size_w;
	int		size_h;
	int		cell;
	int		floor;
	char	*text_north;
	char	*text_south;
	char	*text_west;
	char	*text_east;
	char	*text_sprite;
}				t_map;

/*
** Colors
*/
typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

#endif