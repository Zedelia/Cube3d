/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils_01.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 17:21:31 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/27 20:32:35 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int		get_str_int_len(char *str)
{
	int j;

	j = 0;
	while (ft_isdigit(str[j]) == 1)
		j++;
	return (j);
}

int		occurence_in_charset(char c, char *line)
{
	int	occur;
	int i;

	i = 0;
	occur = 0;
	while (line[i])
	{
		if (line[i] == c)
			occur++;
		i++;
	}
	return (occur);
}