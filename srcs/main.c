#include <stdio.h>
#include "../includes/cube3d.h"

int main(int argc, char *argv[])
{
	(void)argc;
	t_map *map;
	map_init(&map, argv[1]);
	map_printf(map);

	return (0)
;
}
