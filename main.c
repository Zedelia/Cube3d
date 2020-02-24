/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:31:57 by mbos              #+#    #+#             */
/*   Updated: 2020/02/24 12:56:36 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

int		main(int argc, char *argv[])
{
	t_mlx *mlx;

	mlx = NULL;
	if (argc < 2)
		return (return_no_map());
	file_exists(argv[1], mlx);
	mlx_ft_init(&mlx, argv[1]);
	if (argv[2] && (!ft_strcmp(argv[2], "--save") || !ft_strcmp(argv[2], "-s")))
		img_print("screen.bmp", mlx);
	else if (argv[2])
		return (return_false(__func__, "[FAIL] Map and flag needed only", mlx));
	display_update(mlx);
	print_map_infos(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
	display_exit_on_click(mlx);
	mlx_hook(mlx->win, 2, 0, &move_keydown, mlx);
	mlx_loop(mlx->ptr);
	return (0);
}
