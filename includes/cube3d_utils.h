/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cube3d_utils.h                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 13:08:50 by melodiebos   #+#   ##    ##    #+#       */
/*   Updated: 2019/12/27 18:21:40 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CUBE3D_UTILS_H
# define CUBE3D_UTILS_H

#include "cube3d.h"

double		degrees_to_radian(double angle_in_degrees);
int			get_str_int_len(char *str);
t_bool		return_false(const char *namefunc, char const *error_msg);
#endif