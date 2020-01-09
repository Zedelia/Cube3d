/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils_c3d.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 13:08:50 by melodiebos   #+#   ##    ##    #+#       */
/*   Updated: 2020/01/09 17:07:08 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef UTILS_C3D_H
# define UTILS_C3D_H

#include "cube3d.h"

t_bool		return_false(const char *namefunc, char const *error_msg);
t_color		int_to_color(int n);
int			color_to_int(t_color c);
int			get_str_int_len(char *str);
int			occur_in_str(char c,char *line);
int			get_tile(t_map *m, int x, int y);
void		rotate_vect(t_vect *v, float angle);
t_bool		utils_there_is_a_wall_at(t_rays *r, t_vect v, t_mlx *mlx);
float		utils_dist_obstacle_cam(t_vect obs, t_vect cam_pos);
float		degrees_to_radian(float angle_in_degrees);
void		ft_pixel_put(t_mlx *mlx, int x, int y, int color);
void		draw_pix(t_mlx *mlx, t_vect v, int size_obj);

#endif