/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodiebos <melodiebos@student.le-101.f    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/25 10:50:40 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/26 12:45:42 by melodiebos  ###    #+. /#+    ###.fr     */
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
	int		resolution_w;
	int		resolution_h;
	char	*texture_nord;
	char	*texture_sud;
	char	*texture_ouest;
	char	*texture_est;
	char	*texture_sprite;
	int		couleur_plafond;
	int		couleur_sol;
	char	*mapinit;
	char	**map;
	int		map_w;
	int		map_h;
	void	(*ft_parse_cub[9])(char *str, struct s_map *carte);
	char	tabindex[9];
}				t_map;

#endif