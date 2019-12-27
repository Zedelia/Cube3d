#include <stdio.h>
#include <string.h>
#include "../includes/cube3d.h"

int main(int argc, char *argv[])
{
	(void)argc;
	// (void)argv;
	t_map *map;

	map_init(&map, argv[1]);
	map_printf(map);

	return (0)
;
}
