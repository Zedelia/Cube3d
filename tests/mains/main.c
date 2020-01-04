#include <stdio.h>
#include <string.h>
#include "../../includes/cube3d.h"

int main(int argc, char *argv[])
{
	(void)argc;
	// (void)argv;
	t_map *map;
	t_mlx *mlx;
	int ret;


	ret = map_init(&map, argv[1]);
	if (ret != 0)
		ft_printf(GREEN"[PARSING SUCCESS]\n"RESET);
	mlx_ft_init(&mlx, map);
	display_tile(mlx, map);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
	mlx_loop(mlx->ptr);
	return (0)
;
}
