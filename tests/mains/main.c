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
	render_tile(mlx, mlx->map);
	draw_pix(mlx, mlx->cam.pos, 10);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
	render_exit_on_click(mlx);
	mlx_key_hook(mlx->win, &move_keydown, mlx);
	mlx_loop(mlx->ptr);
	return (0);
}
