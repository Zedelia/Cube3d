/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   img_print.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/17 14:18:35 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/22 17:20:00 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */
#include "../../includes/cube3d.h"

/*
**  PRINT_IMAGE
**  open a binary file is the same thing than normal file
**	O_CREAT can create the image with the permissions after it
*/

static void		ft_bitmap_image(t_mlx *mlx, int fd, t_bpm2 bih)
{
	int				x;
	int				y;
	int				ble;
	unsigned char	color[3];

	write(fd, &bih, sizeof(bih));
	y = mlx->map->H - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < mlx->map->W)
		{
			ble = mlx->img.data[y * mlx->map->W + x];
			color[0] = ble % 256;
			ble /= 256;
			color[1] = ble % 256;
			ble /= 256;
			color[2] = ble % 256;
			write(fd, &color, sizeof(color));
			x++;
		}
		y--;
	}
}

void			ft_save_bitmap(const char *filename, t_mlx *mlx)
{
	int			fd;
	t_bpm		bfh;
	t_bpm2		bih;

	ft_memcpy(&bfh.bitmap_type, "BM", 2);
	bfh.file_size = mlx->map->W * mlx->map->H * 4 + 54;
	bfh.reserved1 = 0;
	bfh.reserved2 = 0;
	bfh.offset_bits = 0;
	bih.size_header = sizeof(bih);
	bih.width = mlx->map->W;
	bih.height = mlx->map->H;
	bih.plans = 1;
	bih.bit_count = 24;
	bih.compression = 0;
	bih.image_size = mlx->map->W * mlx->map->H * 4 + 54;
	bih.ppm_x = 2;
	bih.ppm_y = 2;
	bih.clr_used = 0;
	bih.clr_important = 0;
	close(open(filename, O_RDONLY | O_CREAT, S_IRWXU));
	fd = open(filename, O_RDWR);
	write(fd, &bfh, 14);
	ft_bitmap_image(mlx, fd, bih);
	exit(EXIT_SUCCESS);
}
