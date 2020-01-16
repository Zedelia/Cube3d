#include <stdio.h>
#include <string.h>
#include "../../includes/cube3d.h"


int main(int argc, char *argv[])
{
	t_mlx *mlx;

	if (argc != 2)
		return (return_no_map());
	mlx_ft_init(&mlx, argv[1]);
	display_update(mlx);
	display_exit_on_click(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
	mlx_hook(mlx->win, 2, 0, &move_keydown, mlx);
	mlx_loop(mlx->ptr);
	return (0);
}
