/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_init_free.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 14:30:13 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/06 12:04:21 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	map_init(t_map **map, char *map_file, t_mlx *mlx)
{
	if (!(*map = malloc(sizeof(t_map))))
		return (return_false(__func__, "[FAIL] map malloc"));
	(*map)->map_file = map_file;
	(*map)->r_width = -1;
	(*map)->r_height = -1;
	(*map)->cell = -1;
	(*map)->floor = -1;
	(*map)->map_col = -1;
	(*map)->map_lines = -1;
	(*map)->sprite_tab = NULL;
	(*map)->sprite.file = NULL;
	(*map)->sprite1.file = NULL;
	(*map)->sprite2.file = NULL;
	(*map)->sprite3.file = NULL;
	(*map)->west.file = NULL;
	(*map)->east.file = NULL;
	(*map)->north.file = NULL;
	(*map)->south.file = NULL;
	map_parser(mlx);
	(*map)->tile = (*map)->r_width / (*map)->map_col;
	return (True);
}
