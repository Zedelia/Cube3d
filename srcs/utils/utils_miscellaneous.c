/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils_miscellaneous.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/08 15:28:47 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/18 22:28:38 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"


void	rotate_vect(t_vect *r, double angle)
{
	double c;

	c = degrees_to_radian(angle);
	r->x = r->x * cos(c) - r->y * sin(c);
	r->y = r->x * sin(c) + r->y * cos(c);
}

int		get_str_int_len(char *str)
{
	int j;

	j = 0;
	while (ft_isdigit(str[j]) == 0)
		j++;
	while (ft_isdigit(str[j]) == 1)
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