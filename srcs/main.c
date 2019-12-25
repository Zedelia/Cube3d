/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/04/18 03:51:42 by lmarques     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/25 15:36:09 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int     main()
{
    t_mlx	mlx;
	int		count_w;
	int		count_h;
	t_img	lolilol;

	count_h = -1;
	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, WIN_WIDTH, WIN_HEIGHT, "MAROUSTA");
	mlx.img.ptr = mlx_new_image(mlx.ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx.img.data = (int *)mlx_get_data_addr(mlx.img.ptr, &mlx.img.bpp, &mlx.img.size_l,
		&mlx.img.endian);


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

	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img.ptr, 0, 0);
	img_display(&mlx, &lolilol);
	display_exit_on_click(mlx);
	mlx_loop(mlx.ptr);

	return (0);
}