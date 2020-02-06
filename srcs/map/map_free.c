/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_free.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 14:52:00 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 17:36:29 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static void	map_free_tab(t_map *map)
{
	int i;

	i = 0;
	while (i < map->nb_lines)
	{
		ft_memdel((void**)&(map->tab[i]));
		i++;
	}
	ft_memdel((void**)&map->tab);
}

static void		map_free_all_text(t_map *map)
{
	ft_memdel((void**)map->west.file);
	ft_memdel((void**)map->east.file);
	ft_memdel((void**)map->north.file);
	ft_memdel((void**)map->south.file);
	ft_memdel((void**)map->sprite.file);
	if (map->sprite1.file)
		ft_memdel((void**)map->sprite1.file);
	if (map->sprite2.file)
		ft_memdel((void**)map->sprite1.file);
	if (map->sprite3.file)
		ft_memdel((void**)map->sprite1.file);
}

static void		map_free_lines(t_map *map)
{
	while ()
}

void	map_free(t_map **map)
{
	map_free_tab(*map);
	map_free_all_text(*map);
	map_free_lines(*map);
	ft_memdel((void**)&(*map)->sprite_tab);
	ft_memdel((void **)&(*map)->map_file);
}

void	input_free_one(t_input **l_input)
{
	if (!l_input)
		return ;
	(*l_input)->p_input = NULL;
	ft_memdel((void **)&((*l_input)->input_cpy));
	ft_memdel((void **)&((*l_input)->output));
	ft_memdel((void **)&((*l_input)->varg));
	if ((*l_input)->l_flag)
		flag_free(&(*l_input)->l_flag);
	ft_memdel((void**)l_input);
	l_input = NULL;
}

void	input_free(t_input **l_input)
{
	t_input *temp;

	while (*l_input)
	{
		temp = (*l_input)->next;
		input_free_one(l_input);
		*l_input = temp;
	}
	l_input = NULL;
}