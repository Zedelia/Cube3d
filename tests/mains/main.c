#include <stdio.h>
#include <string.h>
#include "../../includes/cube3d.h"

int main(int argc, char *argv[])
{
	(void)argc;
	// (void)argv;
	t_map *map;
	int ret;

	ret = map_init(&map, argv[1]);
	map_printf(map);
	ft_printf("RETURN MAP INIT = %d\n", ret);
	if (ret != 0)
		ft_printf(GREEN"[SUCCESS]\n"RESET);
	return (0)
;
}
