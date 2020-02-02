/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils_c3d.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 13:08:50 by melodiebos   #+#   ##    ##    #+#       */
/*   Updated: 2020/02/02 20:51:41 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef UTILS_C3D_H
# define UTILS_C3D_H

#include "cube3d.h"

t_bool		return_false(const char *namefunc, char const *error_msg);
t_bool		return_no_map();
t_color		int_to_color(int n);
int			color_to_int(t_color c);
int			shade_color(int color, double dist);
int			get_str_int_len(char *str);
int			occur_in_str(char c,char *line);
int			ft_get_tile(t_map *m, int x, int y);
void		rotate_vect(t_vect *v, double angle);
double		degrees_to_radian(double angle_in_degrees);
void		ft_pixel_put(t_mlx *mlx, int x, int y, int color);
void		ft_draw_pix(t_mlx *mlx, t_vect v, int size_obj);
double		ft_math_dist(double hit_x, double hit_y, t_mlx *mlx);
double		dist_correct_fish_eye(t_rays r, t_mlx *mlx, double dist);
int			ft_pixel_get_color(t_img img, int x, int y);
int			get_right_color(t_img img, t_mlx *mlx, t_vect offset, int y);
t_bool		ft_check_incorrect_input_text(char a, char b, char *line);
t_vect		line_inter_line(t_line l1, t_line l2);
t_vect 		norm_vect(t_vect v);
t_bool		is_inter_in_seg(t_vect inter, t_sprite *sp);

#endif
