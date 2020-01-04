#include <stdio.h>
#include <string.h>
#include "../../includes/cube3d.h"

int main(int argc, char *argv[])
{
	(void)argc;
	// (void)argv;
	t_mlx *mlx;
	int ret;
	int lol;

	mlx_ft_init(&mlx, argv[1]);
	if (ret != 0)
		ft_printf(GREEN"[PARSING SUCCESS]\n"RESET);
	map_printf(mlx->map);
	camera_printf(&mlx->camera);
	display_tile(mlx, mlx->map);
	camera_init(mlx);


	// mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
	// display_exit_on_click(mlx);
	// mlx_loop(mlx->ptr);
	return (0);
}
