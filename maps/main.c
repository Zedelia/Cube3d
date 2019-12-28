/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/28 15:28:30 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/28 16:16:36 by mbos        ###    #+. /#+    ###.fr     */
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

	while (i < argc)
	{
		ft_printf(YELLOW"map: %s\n"RESET, argv[i]);
		ret = map_init(&map, argv[i]);
		if (ret == 0)
			ft_printf(RED"ok: %s\n"RESET, argv[i]);
		else if (ret != 0)
		{
			ft_printf(GREEN"ok: %s\n"RESET, argv[i]);
			ft_printf(MAGENTA"Error: map shouldn't be validated\n"RESET);
			return (0);
		}
		i++;
	}
	return (0);
}