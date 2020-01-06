/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   image_clear.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/04 14:45:45 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/04 14:46:14 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	image_clear(t_img *image)
{
	ft_bzero(image->ptr, image->width * image->height * image->bpp);
}