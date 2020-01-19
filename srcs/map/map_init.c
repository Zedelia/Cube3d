/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_init.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 14:30:13 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/01/19 12:43:12 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	map_init(t_map **map, char *map_file, t_mlx *mlx)
{
	if (!(*map = malloc(sizeof(t_map))))
		return (return_false(__func__, "[FAIL] malloc"));
	(*map)->map_file = map_file;
	(*map)->r_width = -1;
	(*map)->r_height = -1;
	(*map)->cell = -1;
	(*map)->floor = -1;
	(*map)->map_col = -1;
	(*map)->map_lines = -1;
	(*map)->text_north = NULL;
	(*map)->text_south = NULL;
	(*map)->text_west = NULL;
	(*map)->text_east = NULL;
	(*map)->text_sprite = NULL;
	if (!(map_parser(*map)))
		return (return_false(__func__, "[FAIL] map parsing"));
	(*map)->tile = (*map)->r_width / (*map)->map_col;
	// map_textures_init(*map, mlx);
	(void)mlx;
	return (True);
}