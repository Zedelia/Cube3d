#include <stdio.h>
#include <string.h>
#include "../includes/cube3d.h"

int main(int argc, char *argv[])
{
	(void)argc;
	// (void)argv;
	t_map *map;

	// printf("%d\n", 57/2);
	map_init(&map, argv[1]);
	map_printf(map);

	return (0)
;
}
