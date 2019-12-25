/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   img_init.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/25 11:33:53 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/25 12:19:31 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	img_init(t_mlx *mlx, t_img **img, char *file)
{
	if (!(*img = malloc(sizeof(t_img))))
		return (false_ret(__func__));
	if (!(img_load_xpm(mlx, file, *img)))
		return (false_ret(__func__));
	return (True);
}