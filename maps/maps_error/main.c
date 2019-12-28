/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/28 15:28:30 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/28 17:00:00 by mbos        ###    #+. /#+    ###.fr     */
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
		ft_printf(YELLOW"\n------> MAP TEST %s <-----\n"RESET, argv[i]);
		ret = map_init(&map, argv[i]);
		if (ret == 0)
			ft_printf(CYAN"ERROR: map non-valid %s\n"RESET, argv[i]);
		else if (ret != 0)
			ft_printf(GREEN"OK: map valid %s\n"RESET, argv[i]);
		i++;
	}
	return (0);
}