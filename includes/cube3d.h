/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cube3d.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/17 13:20:42 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/23 12:22:27 by mbos        ###    #+. /#+    ###.fr     */
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
# define TURN_SPEED 3.5
# define WALK_SPEED 0.2
# define MAP_SCALE 5

# define MAP_INFOS "RNsWESFCLA"
# define MAP_INPUTS "01NSEW"
# define SPRITES "2345"

# define sky_COLOR 0x0F52BA
# define FLOOR_COLOR 0xFF007F

# define DIST_MAX 20.00
# define BLACK 0x000000

# define _XPIXELPERMETER 0xEC4
# define _YPIXELPERMETER 0xEC4
# define DPI 72
# define IMG "img.bmp"

# include "struct.h"
# include "display.h"
# include "rays.h"
# include "map.h"
# include "keys.h"
# include "sprites.h"
# include "print_image.h"

typedef unsigned long long	t_uintmax;
typedef unsigned char		t_uchar;

/*
** MLX CAM init and Free
*/

t_bool		mlx_ft_init(t_mlx **mlx, char *file);
void		mlx_free(t_mlx *mlx);

void		cam_printf(t_cam *cam);
t_bool		cam_init(t_mlx *mlx);
void		cam_get_rotation_angle(t_cam *cam);
void		cam_get_pos(t_cam *cam, t_map *map);

t_bool		img_load_xpm(t_mlx *mlx, char *file, t_img *img);

int			move_keydown(int key, t_mlx *mlx);
t_bool		move_apply(t_move *move, t_mlx *mlx);

void		print_map_infos(t_mlx *mlx);

/*
** Return Functions
*/

t_bool		return_false(const char *namefc, char const *err_msg, t_mlx *mlx);
void		return_success(t_mlx *mlx);
t_bool		return_no_map();
t_bool		file_exists(const char *filename, t_mlx *mlx);

/*
** Colors and pixel Functions
*/

t_color		int_to_color(int n);
int			color_to_int(t_color c);
int			shade_color(int color, double dist);
int			get_correct_color(t_img img, t_mlx *mlx, t_vect offset, int y);
int			get_pixel_color(t_img img, int x, int y);

void		pixel_put(t_mlx *mlx, int x, int y, int color);

/*
** Str Functions used in parsing
*/

int			get_str_int_len(char *str);
int			occur_in_str(char c, char *line);

/*
** Actions on vectors Functions
*/

t_vect		norm_vect(t_vect v);
void		vect_rotate(t_vect *v, double angle);

/*
** Maths
*/

double		degrees_to_radian(double angle_in_degrees);
double		dist_correct_fish_eye(t_rays r, t_mlx *mlx, double dist);
double		ft_math_dist(double hit_x, double hit_y, t_mlx *mlx);

#endif
