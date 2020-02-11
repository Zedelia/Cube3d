/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_image.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/10 13:18:38 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/11 17:19:08 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PRINT_IMAGE_H
# define PRINT_IMAGE_H

# include "cube3d.h"

typedef struct		s_bpm
{
	unsigned char	bitmap_type[2];
	int				file_size;
	short			reserved1;
	short			reserved2;
	unsigned int	offset_bits;
}					t_bpm;

typedef struct		s_bpm2
{
	unsigned int	size_header;
	unsigned int	width;
	unsigned int	height;
	short int		planes;
	short int		bit_count;
	unsigned int	compression;
	unsigned int	image_size;
	unsigned int	ppm_x;
	unsigned int	ppm_y;
	unsigned int	clr_used;
	unsigned int	clr_important;
}					t_bpm2;

void			ft_save_bitmap(const char *filename, t_mlx *mlx);


#endif
