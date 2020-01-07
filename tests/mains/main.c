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
	t_rays rays[mlx->map->r_width];
	cam_init(mlx);
	map_printf(mlx->map);
	cam_printf(&mlx->cam);
	rays_tab_init(rays, mlx);
	rays_printf_tab(mlx, rays);


	// mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
	// display_exit_on_click(mlx);
	// mlx_loop(mlx->ptr);
	return (0);
}
