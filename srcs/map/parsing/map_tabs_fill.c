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

static t_bool	get_sprite_img(char a, t_sprite *sp, t_map *map, t_mlx *mlx)
{
	if (a == '2')
		sp->img = &map->sprite;
	if (a == '3' && map->sprite1.file)
		sp->img = &map->sprite1;
	else if (a == '3')
		return (return_false(__func__, "[FAIL] wrong sprite identifier", mlx));
	if (a == '4' && map->sprite2.file)
		sp->img = &map->sprite2;
	else if (a == '4' )
		return (return_false(__func__, "[FAIL] wrong sprite identifier", mlx));
	if (a == '5' && map->sprite3.file)
		sp->img = &map->sprite3;
	else if (a == '5')
		return (return_false(__func__, "[FAIL] wrong sprite identifier", mlx));
	return (True);
}

static void			parse_line(t_maparse *line, t_map *map, int y, t_mlx *mlx)
{
	int i;
	int x;
	static int s = 0;

	i = 0;
	x = 0;
	while (line->line[i])
	{
		if (ft_isincharset(line->line[i], SPRITES))
		{
			map->sprite_tab[s].y = y;
			map->sprite_tab[s].x = x;
			get_sprite_img(line->line[i], &map->sprite_tab[s], map, mlx);
			s++;
		}
		if (ft_isincharset(line->line[i], MAP_INPUTS)
				|| ft_isincharset(line->line[i], SPRITES))
			map->tab[y][x++] = line->line[i] - 48;
		i++;
	}
	while (x < map->nb_col)
		map->tab[y][x++] = 1;
}

t_bool 			map_tabs_fill(t_map *map, t_mlx *mlx)
{
	t_maparse 	*temp;
	int 		s;
	int 		i;
	int			y;

	i = 0;
	y = 0;
	s = 0;
	temp = map->lines;
	while (temp && y < map->nb_lines)
	{
		parse_line(temp, map, y, mlx);
		temp = temp->next;
		y++;
	}
	return (True);
}