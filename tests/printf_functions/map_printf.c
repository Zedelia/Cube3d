/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map_printf.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/26 15:08:12 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/07 15:54:31 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static void 	map_tab_printf(t_map *map)
{
	int h;
	int w;

	h = 0;
	w = 0;
	ft_printf("\nMAP:\n");
	while (h < map->nb_lines)
	{
		while (w < map->nb_col)
		{
			ft_printf("%d", map->tab[h][w]);
			w++;
		}
		ft_printf("\n");
		w = 0;
		h++;
	}
}

 void 	sprite_tab_printf(t_map *map)
{
	int i;
	t_sprite temp;

	i = 0;
	ft_printf("\n\nSPRITES:\n");
	while (i < map->nb_sprites)
	{
		temp = map->sprite_tab[i];
		printf("\nsp x: %d | sp y: %d\ndist: %f\nvisible? %d\n", temp.x, temp.y, temp.dist, temp.visible);
		printf("sp p1: %f | sp p2: %f\n", temp.p1.x, temp.p2.x);
		printf("fst ray printed id : %d\nlast ray printed id : %d\n", temp.fst_ray_print, temp.last_ray_print );
				printf("fst ray printed id : %f\nlast ray printed id : %f\n", temp.r_fst_hit.id, temp.r_last_hit.id );
		// printf("fst ray  dist : %f\nlast ray  dist : %f\n", temp.r_before.distance, temp.r_after.distance );
		printf("sp dist: %f\n", temp.dist);
		printf("sp img: %s\n", temp.img->file);
		printf("sp img: %d\n", temp.img->width);
		i++;
	}
}

// TODO supprimer les printf
void	map_printf(t_map *map)
{
	if (!map)
		return ;
	if (map->map_file)
		ft_printf(YELLOW"--- MAP_FILE: %s---\n"RESET, map->map_file);
	ft_printf("r_width: %d\nr_height: %d\nmap-col: %d\nmap-lines: %d\ncell: %d\nfloor: %d\n",
		map->r_width, map->r_height, map->nb_col, map->nb_lines, map->cell, map->floor);
	if (map->north.file)
		ft_printf("north: %s\n", map->north.file);
	if (map->south.file)
		ft_printf("south: %s\n", map->south.file);
	if (map->west.file)
		ft_printf("west: %s\n", map->west.file);
	if (map->east.file)
		ft_printf("east: %s\n", map->east.file);
	if (map->sprite.file)
		ft_printf("sprite: %s\n", map->sprite.file);
	// if (map->map_char)
	// 	ft_printf("map_char: %s\n", map->map_char);
	if (map->tab)
		map_tab_printf(map);
}