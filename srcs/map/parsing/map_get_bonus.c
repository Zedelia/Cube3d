/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_get_bonus.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/22 21:39:31 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/23 12:09:39 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../../includes/cube3d.h"

t_bool	map_parse_life(t_map *map, char *line, t_mlx *mlx)
{
	int start;

	if (map->life.file != NULL)
		return (return_false(__func__, "[FAIL] info several times", mlx));
	start = 0;
	while (line[start] && line[start] != '.')
		start++;
	if (!(map->life.file = strdup(&line[start])))
		return (return_false(__func__, "[FAIL] strdup", mlx));
	mlx->bonus2 = True;
	return (True);
}

t_bool	map_parse_frame(t_map *map, char *line, t_mlx *mlx)
{
	int start;

	if (map->frame.file != NULL)
		return (return_false(__func__, "[FAIL] info several times", mlx));
	start = 0;
	while (line[start] && line[start] != '.')
		start++;
	if (!(map->frame.file = strdup(&line[start])))
		return (return_false(__func__, "[FAIL] strdup", mlx));
	mlx->bonus1 = True;
	return (True);
}
