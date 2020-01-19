/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils_miscellaneous.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/08 15:28:47 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/19 12:15:11 by mbos        ###    #+. /#+    ###.fr     */
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

t_bool	ft_check_incorrect_input_text(char a, char b, char *line)
{
	int start;

	start = 0;
	while (line[start] != a && line[start])
		start++;
	if (line[start + 1] && b && line[start + 1] != b)
		return (return_false(__func__, "[FAIL] wrong texture identifier"));
	start += b ? 2 : 1;
	while (line[start] < 33 && line[start])
		start++;
	if (line[start] != '.')
		return (return_false(__func__, "[FAIL] wrong texture input"));
	return (True);
}