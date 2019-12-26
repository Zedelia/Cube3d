/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_free.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 14:52:00 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/26 17:27:11 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	map_free(t_map **map)
{
	ft_memdel((void **)&(*map)->map_file);
	ft_memdel((void **)&(*map)->text_north);
	ft_memdel((void **)&(*map)->text_south);
	ft_memdel((void **)&(*map)->text_west);
	ft_memdel((void **)&(*map)->text_east);
	ft_memdel((void **)&(*map)->text_sprite);
}