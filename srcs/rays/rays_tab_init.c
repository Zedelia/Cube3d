/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rays_tab_init.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 14:24:55 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/27 18:49:19 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool  rays_tab_init(t_rays *rays_tab)
{
    int     i;

    i = 0;
    if(!(rays_tab = malloc(WIN_WIDTH * sizeof(t_vect))))
		return (return_false(__func__, "[FAIL] malloc"));
    rays_tab[i] = ray_setup((-(FOV_DEG/2)));
    i++;
    while (i < WIN_WIDTH)
    {
        rays_tab[i] = ray_setup((i - WIN_WIDTH * 0.5) * FOV_DEG / WIN_WIDTH);
        i++;
    }
    return (True);
}