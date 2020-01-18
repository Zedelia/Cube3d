/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main-maps.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/28 15:28:30 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/18 23:43:02 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string.h>
#include "../../includes/cube3d.h"


int main(int argc, char **argv)
{
	int ret;
	(void)argc;
	t_map *map;
	t_mlx m;

	ret = map_init(&map, argv[1], &m);
	if (ret != 0)
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
	return (0);
}




// int main(int argc, char **argv)
// {
// 	int ret;
// 	t_map *map;
// 	int i = 1;

// 	while (i < argc)
// 	{
// 		// ft_printf(YELLOW"\n------> MAP TEST %s <-----\n"RESET, argv[i]);
// 		ret = map_init(&map, argv[i]);
// 		if (ret == 0)
// 			exit(EXIT_SUCCESS);
// 			// ft_printf(CYAN"ERROR: map non-valid %s\n"RESET, argv[i]);
// 		// else if (ret != 0)
// 		// 	ft_printf(GREEN"OK: map valid %s\n"RESET, argv[i]);
// 		i++;
// 	}
// 	exit(EXIT_FAILURE);
// 	return (0);
// }