/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_misskyaneous.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:24:15 by mbos              #+#    #+#             */
/*   Updated: 2020/02/17 14:24:16 by mbos             ###   ########lyon.fr   */
/*                                                                            */
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
