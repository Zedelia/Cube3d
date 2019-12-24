/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/04/18 03:51:42 by lmarques     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/24 16:51:38 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int     load_xpm(t_mlx *mlx, char *file, t_img *img)
{
    if (!(img->img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, file,            \
                                &img->width, &img->height)))
        return (0);
    if (!(img->data = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp,    \
                                &img->size_l, &img->endian)))
        return (0);
    return (1);
}

int exit_propre(void *param)
{
    (void)param;
    exit(0);
}

int	main(void)
{
	t_mlx	mlx;
	int		count_w;
	int		count_h;
	t_img 	dragon;
	int		i;
	int 	j;

	count_h = -1;
	mlx.mlx_ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Milou");
	mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx.img.data = (int *)mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bpp, &mlx.img.size_l,
		&mlx.img.endian);

	if (!(load_xpm(&mlx, "dragon.xpm", &dragon)))
		return (0);

	i = 1;
	j = 1;

	while (i < 13)
	{
		while (++count_h < (WIN_HEIGHT * i) / 12)
		{
			count_w = -1;
			while (j < 13)
			{
				while (++count_w < (WIN_WIDTH * j) / 12)
					mlx.img.data[count_h * WIN_WIDTH + count_w] = 0;
				j++;
				count_w--;
				while (++count_w < (WIN_WIDTH * j) / 12)
					mlx.img.data[count_h * WIN_WIDTH + count_w] = 0xFFFFFF;
				j++;
				count_w--;
			}
			j = 1;
		}
		count_h--;
		i++;
		while (++count_h < (WIN_HEIGHT * i) / 12)
		{
			count_w = -1;
			while (j < 13)
			{
				while (++count_w < (WIN_WIDTH * j) / 12)
					mlx.img.data[count_h * WIN_WIDTH + count_w] = 0;
				j++;
				count_w--;
				while (++count_w < (WIN_WIDTH * j) / 12)
					mlx.img.data[count_h * WIN_WIDTH + count_w] = 0xFFFFFF;
				j++;
				count_w--;
			}
			j = 0;
		}
		count_h--;
		i++;
	}
	// while (++count_h < WIN_HEIGHT / 2)
	// {
	// 	count_w = -1;
	// 	while (++count_w < WIN_WIDTH / 2)
	// 		mlx.img.data[count_h * WIN_WIDTH + count_w] = 0;
	// 	while (++count_w < WIN_WIDTH)
	// 		mlx.img.data[count_h * WIN_WIDTH + count_w] = 0xFFFFFF;
	// }
	// while (++count_h < (WIN_HEIGHT * 3) / 4)
	// {
	// 	count_w = -1;
	// 	while (++count_w < WIN_WIDTH  / 2)
	// 		mlx.img.data[count_h * WIN_WIDTH + count_w] = 0xFFFFFF;
	// 	while (++count_w < WIN_WIDTH)
	// 		mlx.img.data[count_h * WIN_WIDTH + count_w] = 0;
	// }

	// while (++count_h < WIN_HEIGHT)
	// {
	// 	count_w = -1;
	// 	while (++count_w < WIN_WIDTH  / 2)
	// 		mlx.img.data[count_h * WIN_WIDTH + count_w] = 0;
	// 	while (++count_w < WIN_WIDTH)
	// 		mlx.img.data[count_h * WIN_WIDTH + count_w] = 0xFFFFFF;
	// }

	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, mlx.img.img_ptr, 0, 0);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, dragon.img_ptr,
							WIN_WIDTH / 2 - 100 , WIN_HEIGHT / 2 - 100);
	mlx_hook(mlx.win, 17, 0, &exit_propre, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
