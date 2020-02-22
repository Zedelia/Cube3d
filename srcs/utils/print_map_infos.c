/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_map_infos.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/22 17:35:44 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/22 17:49:56 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	print_map_infos(t_mlx *mlx)
{
	t_color floor;
	t_color	roof;

	ft_printf("\n resolution	: %d * %d\n", mlx->map->W, mlx->map->H);
	ft_printf("\n no texture 	: %s\n", mlx->map->north.file);
	ft_printf("\n so texture	: %s\n", mlx->map->south.file);
	ft_printf("\n ea texture	: %s\n", mlx->map->east.file);
	ft_printf("\n we texture	: %s\n", mlx->map->west.file);
	ft_printf("\n sprite texture	: %s\n", mlx->map->sprite.file);
	floor = int_to_color(mlx->map->floor);
	ft_printf("\n Floor color	: R: %d | G: %d | B: %d\n",
			floor.r, floor.g, floor.b);
	roof = int_to_color(mlx->map->floor);
	ft_printf("\n Floor color	: R: %d | G: %d | B: %d\n",
			roof.r, roof.g, roof.b);
	ft_printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
	ft_printf("━━━━━━━━━━━━━━━━━━━━\n");
	ft_printf("\t\t\tPARAMETERS COMPLETED\n");
	ft_printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
	ft_printf("━━━━━━━━━━━━━━━━━━━━\n\n");
}