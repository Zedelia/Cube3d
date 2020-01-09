#include <stdio.h>
#include <string.h>
#include "../../includes/cube3d.h"


int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	t_mlx *mlx;
	int pix;
	int lol;

	mlx_ft_init(&mlx, argv[1]);
	// rays_casting(mlx);
	display_update(mlx);
	display_exit_on_click(mlx);
	mlx_key_hook(mlx->win, &move_keydown, mlx);
	mlx_loop(mlx->ptr);
	return (0);
}
