#include <stdio.h>
#include <string.h>
#include "../../includes/cube3d.h"

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	t_mlx *mlx;
	int ret;
	int lol;

	mlx_ft_init(&mlx, argv[1]);
	map_printf(mlx->map);
	cam_printf(&mlx->cam);
	rays_printf_tab(mlx, mlx->cam.ray_tab);
	rays_casting(mlx);
	printf("\n------------*************************-----------\n");
	rays_printf_tab(mlx, mlx->cam.ray_tab);

	// mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
	// display_exit_on_click(mlx);
	// mlx_loop(mlx->ptr);
	return (0);
}
