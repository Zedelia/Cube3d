/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   img_print.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/10 18:21:29 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 18:21:32 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
** All you need to save the screen
*/

typedef struct __attribute__((packed))		s_fileheader
{
	unsigned char	signature[2];
	unsigned int	filesize;
	unsigned int	reserved;
	unsigned int	fileoffset_to_pixelarray;
}					t_fileheader;

typedef struct __attribute__((packed))		s_imageheader
{
	unsigned int	dibheadersize;
	unsigned int	width;
	unsigned int	height;
	int16_t			planes;
	int16_t			bitsperpixel;
	unsigned int	compression;
	unsigned int	imagesize;
	unsigned int	xpixelpermeter;
	unsigned int	ypixelpermeter;
	unsigned int	numcolorspallette;
	unsigned int	mostimpcolor;
}					t_imageheader;

typedef struct __attribute__((packed))		s_bitmap
{
	t_fileheader	fileheader;
	t_imageheader	imageheader;
}					t_bitmap;

typedef struct		s_bgr
{
	unsigned char	blue;
	unsigned char	green;
	unsigned char	red;
}					t_bgr;