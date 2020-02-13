/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/13 14:31:57 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/13 17:18:49 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/cube3d.h"


int main(int argc, char *argv[])
{
	t_mlx *mlx;

	mlx = NULL;
	// if (argc < 2)
	// 	return (return_no_map());
	// file_exists("./tests/maps/maps_error/map_colors.cub", mlx);
	mlx_ft_init(&mlx, "./tests/maps/maps_error/map_colors.cub");
	display_update(mlx);
	if (argv[2] && (!ft_strcmp(argv[2], "––save") || !ft_strcmp(argv[2], "–s")))
		ft_save_bitmap("screen.bmp", mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
	display_exit_on_click(mlx);
	mlx_hook(mlx->win, 2, 0, &move_keydown, mlx);
	mlx_loop(mlx->ptr);
	return (0);
}