/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ray_tab_init.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/08 13:32:31 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 13:32:41 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	rays_tab_init(t_mlx *mlx)
{
    int		i;
	float	r_angle;

    i = 0;
	if(!(mlx->cam.ray_tab = malloc(sizeof(t_rays) * mlx->map->r_width)))
		return (return_false(__func__, "[FAIL] malloc rays tab"));
    mlx->cam.ray_tab[i] = ray_init((-(FOV_DEGREE/2)));
    i++;
    while (i < mlx->map->r_width)
    {
		r_angle =(i - mlx->map->r_width * 0.5) * FOV_DEGREE / mlx->map->r_width;
        mlx->cam.ray_tab[i] = ray_init(r_angle);
        i++;
    }
    return (True);
}
