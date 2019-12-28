#include <stdio.h>
#include <string.h>
#include "../includes/cube3d.h"

int main(int argc, char *argv[])
{
	(void)argc;
	// (void)argv;
	t_map *map;
	int ret;

	ret = map_init(&map, argv[1]);
	ft_printf("RETURN MAP INIT = %d\n", ret);
	map_printf(map);

	return (0)
;
}
