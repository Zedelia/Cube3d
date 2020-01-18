#include <stdio.h>
#include <string.h>
#include "../../includes/cube3d.h"


int main(int argc, char *argv[])
{
	t_mlx *mlx;
	t_img img;

	if (argc != 2)
		return (return_no_map());
	mlx_ft_init(&mlx, argv[1]);
	map_textures_init(mlx->map, mlx);
	display_update(mlx);
	map_printf(mlx->map);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
	display_exit_on_click(mlx);
	mlx_hook(mlx->win, 2, 0, &move_keydown, mlx);
	mlx_loop(mlx->ptr);
	return (0);
}
