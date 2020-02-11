/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils_miscellaneous.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/08 15:28:47 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/11 17:37:06 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int		get_str_int_len(char *str)
{
	int j;

	j = 0;
	while (str[j] && ft_isdigit(str[j]) == 0)
		j++;
	while (str[j] && ft_isdigit(str[j]) == 1)
		j++;
	while (str[j] && ft_isdigit(str[j]) == 0)
		j++;
	return (j);
}

int		occur_in_str(char c, char *line)
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
