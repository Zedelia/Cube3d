/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rays_init.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: melodiebos <melodiebos@student.le-101.f    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 12:48:52 by melodiebos   #+#   ##    ##    #+#       */
/*   Updated: 2019/12/26 13:05:43 by melodiebos  ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool  rays_init(t_rays rays)
{
	rays.x = 0;
	rays.y = 1;
	rays.ox = 0;
	rays.oy = 0 ;
	return (True);
}