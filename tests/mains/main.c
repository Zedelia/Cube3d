#include <stdio.h>
#include <string.h>
#include "../../includes/cube3d.h"


int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	t_mlx *mlx;
	float pix = 4.5;
	int lol;

	mlx_ft_init(&mlx, argv[1]);
	display_tile(mlx, mlx->map);
	rays_printf_tab(mlx, mlx->cam.ray_tab);
	printf("\n****************/************/**********\n\n");
	// rays_casting(mlx);
	// rays_printf_tab(mlx, mlx->cam.ray_tab);
	display_update(mlx);
	display_exit_on_click(mlx);
	mlx_key_hook(mlx->win, &move_keydown, mlx);
	mlx_loop(mlx->ptr);
	return (0);
}
