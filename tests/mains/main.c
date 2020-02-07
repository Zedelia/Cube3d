#include <stdio.h>
#include <string.h>
#include "../../includes/cube3d.h"


int main(int argc, char *argv[])
{
	t_mlx *mlx;
	// t_img img;

	mlx = NULL;
	if (argc != 2)
		return (return_no_map());
	if (!argv[1])
	// ici mettre les instructions dans le return
		return (return_false(__func__, "[FAIL] provide map file", mlx));
	file_exists(argv[1], mlx);
	mlx_ft_init(&mlx, argv[1]);
	display_update(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
	display_exit_on_click(mlx);
	mlx_hook(mlx->win, 2, 0, &move_keydown, mlx);
	mlx_loop(mlx->ptr);
	return (0);
}
