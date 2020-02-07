/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_init.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/06 16:08:41 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/07 16:16:48 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#include "../../includes/cube3d.h"

void	map_init_text(t_map **map)
{
	(*map)->sprite_tab = NULL;
	(*map)->sprite.file = NULL;
	(*map)->sprite1.file = NULL;
	(*map)->sprite2.file = NULL;
	(*map)->sprite3.file = NULL;
	(*map)->west.file = NULL;
	(*map)->east.file = NULL;
	(*map)->north.file = NULL;
	(*map)->south.file = NULL;
}

t_bool	map_init(t_map **map, char *map_file, t_mlx *mlx)
{
	if (!(*map = malloc(sizeof(t_map))))
		return (return_false(__func__, "[FAIL] map malloc", mlx));
	(*map)->map_file = map_file;
	(*map)->r_width = -1;
	(*map)->r_height = -1;
	(*map)->cell = -1;
	(*map)->floor = -1;
	(*map)->nb_col = -1;
	(*map)->nb_lines = -1;
	(*map)->tab = NULL;
	(*map)->sprite_tab = NULL;
	(*map)->lines = NULL;
	map_init_text(map);
	map_parser(mlx);
	(*map)->tile = (*map)->r_width / (*map)->nb_col;
	return (True);
}
