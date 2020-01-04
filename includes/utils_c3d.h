/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils_c3d.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 13:08:50 by melodiebos   #+#   ##    ##    #+#       */
/*   Updated: 2020/01/04 13:59:51 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef UTILS_C3D_H
# define UTILS_C3D_H

#include "cube3d.h"

int			get_str_int_len(char *str);
t_bool		return_false(const char *namefunc, char const *error_msg);
int			occur_in_str(char c,char *line);
int			get_tile(t_map *m, int x, int y);
double		degrees_to_radian(double angle_in_degrees);
int			color_to_int(t_color c);
t_color		int_to_color(int n);
void		rotate_vect(t_vect *vect, float angle);

#endif