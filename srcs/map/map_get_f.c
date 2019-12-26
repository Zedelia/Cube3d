/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_get_f.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 20:06:28 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/26 20:31:01 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	read_colors(int *red, int *green, int *blue, char *line)
{
	int i;
	int j;
	char *temp;

	i = 0;
	while (ft_isdigit(line[i]) == 0)
		i++;
	j = get_str_int_len(&line[i]);
	*red = ft_atoi(&line[i]);





}