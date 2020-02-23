/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   return_func.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/17 14:24:10 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/23 12:22:28 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

t_bool	return_false(const char *namefunc, char const *error_msg, t_mlx *mlx)
{
	ft_printf(RED"");
	perror(namefunc);
	if (error_msg)
		ft_printf(RED"Error"RESET"\n-> %s\n\n", error_msg);
	mlx_free(mlx);
	exit(EXIT_FAILURE);
	return (False);
}

void	return_success(t_mlx *mlx)
{
	mlx_free(mlx);
	exit(EXIT_SUCCESS);
}

t_bool	return_no_map(void)
{
	ft_printf(RED"");
	ft_printf(RED"Error"RESET"\n-> A map is needed\n\n");
	exit(EXIT_FAILURE);
	return (False);
}

t_bool	file_exists(const char *filename, t_mlx *mlx)
{
	FILE	*file;
	int		i;

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
	return (return_false(__func__, "[FAIL] Map doesn't exists", mlx));
}
