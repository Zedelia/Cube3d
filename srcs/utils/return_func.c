/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   return_func.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/27 18:11:41 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/27 18:57:44 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	return_false(const char *namefunc, char const *error_msg)
{
	perror(namefunc);
	if (error_msg)
		ft_printf(RED"Error\n%s\n"RESET, error_msg);
	return (False);;
}
