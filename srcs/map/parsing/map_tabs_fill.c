/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_tabs_fill.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/28 16:34:38 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/21 13:28:51 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

static t_bool	get_sprite_img(char a, t_sprite *sp, t_map *map)
{
	if (a == '2')
		sp->img = &map->sprite;
	else if (a == '3')
		sp->img = &map->sprite1;
	else if (a == '4')
		sp->img = &map->sprite2;
	else if (a == '5')
		sp->img = &map->sprite3;
	else
		return (return_false(__func__, "[FAIL] wronf input in map"));
	return (True);
}

t_bool 			map_tabs_fill(t_map *map)
{
	int x;
	int y;
	int i;
	int s;

	y = 0;
	i = 0;
	s = 0;
	while (map->map_char[i] && y < map->map_lines)
	{
		x = 0;
		while (map->map_char[i] && x < map->map_col)
		{
			if (ft_isincharset(map->map_char[i], MAP_INPUTS)
					|| ft_isincharset(map->map_char[i], SPRITES))
			{
				if (ft_isincharset(map->map_char[i], SPRITES))
				{
					map->sprite_tab[s].y = y;
					map->sprite_tab[s].x = x;
					get_sprite_img(map->map_char[i], &map->sprite_tab[s], map);
					s++;
				}
				map->tab[y][x] = map->map_char[i] - 48;
				x++;
			}
			i++;
		}
		y++;
	}
	return (True);
}