/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/28 15:28:30 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/28 15:42:40 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>
#include "../includes/cube3d.h"


int main(int argc, char **argv)
{
	int ret;
	t_map *map;
	int i = 1;

	argc += 1;

	while (i < argc)
	{
		ret = map_init(&map, argv[i]);
		map_printf(map);
		if (ret == 0)
			ft_printf(RED"ok: %s\n"RESET, argv[i]);
		if (ret != 0)
		{
			ft_printf(MAGENTA"Error: map shouldn't be validated\n"RESET);
			return (0);
		}
		i++;
	}
	return (0);
}