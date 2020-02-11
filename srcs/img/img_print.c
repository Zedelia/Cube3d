/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   img_print.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/10 13:18:30 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/11 15:05:37 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

/*
**  PRINT_IMAGE
**  open a binary file is the same thing than normal file
**	O_CREAT can create the image with the permissions after it
*/

static void		fill_bmp_header(t_mlx *mlx, int fd)
{
	t_bitmap bitmap;

	ft_memcpy(bitmap.fileheader.signature, "BM", 2);
	bitmap.fileheader.filesize = mlx->img.width * mlx->img.height * 3 + sizeof(t_bitmap);
	bitmap.fileheader.reserved = 0;
	bitmap.fileheader.fileoffset_to_pixelarray = sizeof(t_bitmap);
	bitmap.imageheader.dibheadersize = sizeof(t_imageheader);
	bitmap.imageheader.width = mlx->img.width;
	bitmap.imageheader.height = mlx->img.height;
	bitmap.imageheader.planes = 1;
	bitmap.imageheader.bitsperpixel = 24;
	bitmap.imageheader.compression = 0;
	bitmap.imageheader.imagesize = mlx->img.width * mlx->img.height;
	bitmap.imageheader.ypixelpermeter = _YPIXELPERMETER;
	bitmap.imageheader.xpixelpermeter = _XPIXELPERMETER;
	bitmap.imageheader.numcolorspallette = 0;
	bitmap.imageheader.mostimpcolor = 0;
	write(fd, &bitmap.fileheader, 14);
	write(fd, &bitmap.imageheader, sizeof(t_imageheader));
}

static int		init_rev_image(t_mlx *mlx, t_bgr **rev_image)
{
	int		cpy;
	int		i;
	int		j;
	char	*image;

	image = (char *)mlx->img.data;
	if (!(*rev_image = malloc(mlx->img.width * mlx->img.height * sizeof(t_bgr))))
		return (-1);
	i = 0;
	while (i < mlx->img.height)
	{
		j = mlx->img.width - 1;
		while (j >= 0)
		{
			cpy = mlx->img.width * i + j;
			(*rev_image)[cpy].blue = image[cpy * 4];
			(*rev_image)[cpy].green = image[cpy * 4 + 1];
			(*rev_image)[cpy].red = image[cpy * 4 + 2];
			j--;
				printf("coucou\n");
		}
		i++;
	}
	return (0);
}

static void		fill_image(t_mlx *mlx, t_bgr *rev_image, int fd)
{
	int		i;
	int		remainder;
	char	c_null;
	char	c_huge;

	c_null = 0;
	c_huge = 0xFF;
	i = mlx->map->r_height - 1;
	while (i >= 0)
	{
		remainder = 4 - (mlx->img.width * sizeof(t_bgr)) % 4;
		if (remainder == 4)
			remainder = 0;
		write(fd, rev_image + i * mlx->img.width, mlx->img.width * sizeof(t_bgr));
		while (remainder > 1)
			remainder -= write(fd, &c_null, 1);
		write(fd, &c_huge, remainder);
		i--;
	}
}

int				print_image(t_mlx *mlx)
{
	int		fd;
	t_bgr	*rev_image;

	fd = open(IMG, O_WRONLY | O_CREAT, 00755);
	if (fd < 0)
		return (return_false(__func__, "[FAIL] create img bmp", mlx));
	fill_bmp_header(mlx, fd);
	if (init_rev_image(mlx, &rev_image) == -1)
	{
		close(fd);
		return (return_false(__func__, "[FAIL] create img bmp", mlx));
	}
	fill_image(mlx, rev_image, fd);
	free(rev_image);
	close(fd);
	return (0);
}
