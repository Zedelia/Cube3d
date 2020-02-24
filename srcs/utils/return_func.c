/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:24:10 by mbos              #+#    #+#             */
/*   Updated: 2020/02/24 17:33:13 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

static void		how_to_use(void)
{
	ft_printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
	ft_printf("━━━━━━━━━━━━━━━━━━━━\n");
	ft_printf("\t\t\tCOMMENT L'UTILISER\n");
	write(1, "\n\n", 2);
	write(1, "  Exemple : ./Cub3D 'map'     \n", 32);
	write(1, "\x1b[33m Choisis ta carte               \n", 38);
	write(1, "\x1b[36m. 1 : maps/map_01_silver.cub       \n", 42);
	write(1, ". 2 : maps/map_02_stone.cub       \n", 35);
	write(1, ". 3 : maps/map_03_blue.cub       \n", 35);
	write(1, ". 4 : maps/map_04_pokemon.cub  \n", 33);
	write(1, ". 5 : maps/map_05_candies.cub   \n", 34);
	write(1, ". 6 : maps/map_bonus_gravityfalls.cub        \n", 47);
	write(1, "\x1b[32m ou crée ta propre carte  \n", 35);
	write(1, "\033[0m", 4);
	ft_printf("\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
	ft_printf("━━━━━━━━━━━━━━━━━━━━\n");
}

t_bool			return_false(const char *name, char const *err_msg, t_mlx *mlx)
{
	ft_printf(RED"");
	perror(name);
	if (err_msg)
		ft_printf(RED"Error"RESET"\n-> %s\n\n", err_msg);
	mlx_free(mlx);
	exit(EXIT_FAILURE);
	how_to_use();
	return (False);
}

void			return_success(t_mlx *mlx)
{
	mlx_free(mlx);
	exit(EXIT_SUCCESS);
}

t_bool			return_no_map(void)
{
	ft_printf(RED"");
	ft_printf(RED"Error"RESET"\n-> A map is needed\n\n");
	how_to_use();
	exit(EXIT_FAILURE);
	return (False);
}

t_bool			file_exists(const char *filename, t_mlx *mlx)
{
	FILE		*file;
	int			i;
	const char	*s;

	s = "[FAIL] Map doesn't exists.\nMake sure you are using a .cub map\n";
	i = 0;
	if ((file = fopen(filename, "r")))
	{
		fclose(file);
		while (filename[i])
			i++;
		i--;
		if (filename[i] == 'b' && filename[i - 1] == 'u'
				&& filename[i - 2] == 'c' && filename[i - 3] == '.'
				&& filename[i - 4])
			return (True);
	}
	how_to_use();
	return (return_false(__func__, s, mlx));
}
