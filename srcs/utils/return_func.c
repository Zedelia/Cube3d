/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   return_func.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/27 18:11:41 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 11:28:41 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	return_false(const char *namefunc, char const *error_msg)
{
	ft_printf(RED""); // TODO free les malloc
	perror(namefunc);
	if (error_msg)
		ft_printf(RED"Error"RESET"\n-> %s\n\n", error_msg);
	exit(EXIT_FAILURE);
	return (False);
}
