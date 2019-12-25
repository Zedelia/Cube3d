/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/04/18 03:51:42 by lmarques     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/25 15:20:13 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int     main()
{
    t_mlx	mlx;
	int		count_w;
	int		count_h;
	t_img	marousta;

	count_h = -1;
	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, WIN_WIDTH, WIN_HEIGHT, "MAROUSTA");
	mlx.img.ptr = mlx_new_image(mlx.ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx.img.data = (int *)mlx_get_data_addr(mlx.img.ptr, &mlx.img.bpp, &mlx.img.size_l,
		&mlx.img.endian);

	t_img	lolilol;

	img_load_xpm(&mlx, "dragon.xpm", &lolilol);

	while (++count_h <= (WIN_HEIGHT / 6))
	{
		count_w = -1;
		while (++count_w < WIN_WIDTH)
		{
				mlx.img.data[count_h * WIN_WIDTH + count_w] = 0xFF0000 ;
		}
	}
    while (++count_h < (WIN_HEIGHT * 2) / 6)
	{
		count_w = -1;
		while (++count_w < WIN_WIDTH)
		{
				mlx.img.data[count_h * WIN_WIDTH + count_w] = 0xFF8B00;
		}
	}
	while (++count_h < (WIN_HEIGHT * 3) / 6)
	{
		count_w = -1;
		while (++count_w < WIN_WIDTH)
		{
				mlx.img.data[count_h * WIN_WIDTH + count_w] = 0xFFE800;
		}
	}
	while (++count_h < (WIN_HEIGHT * 4) / 6)
	{
		count_w = -1;
		while (++count_w < WIN_WIDTH)
		{
				mlx.img.data[count_h * WIN_WIDTH + count_w] = 0x09AD1F;
		}
	}
	while (++count_h < (WIN_HEIGHT * 5) / 6)
	{
		count_w = -1;
		while (++count_w < WIN_WIDTH)
		{
				mlx.img.data[count_h * WIN_WIDTH + count_w] = 0xd7d1bf;
		}
	}
	while (++count_h < WIN_HEIGHT)
	{
		count_w = -1;
		while (++count_w < WIN_WIDTH)
		{
				mlx.img.data[count_h * WIN_WIDTH + count_w] = 0x86009E;
		}
	}

	printf("%d\n", (int) 0xd7d1bf);

	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img.ptr, 0, 0);
	mlx_put_image_to_window(mlx.ptr, mlx.win, marousta.ptr, 100, 120);
	mlx_put_image_to_window(mlx.ptr, mlx.win, lolilol.ptr, 100, 150);
	mlx_display_exit(mlx);
	mlx_loop(mlx.ptr);

	return (0);
}