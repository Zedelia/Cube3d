/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cube3d.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/22 15:29:00 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2019/12/24 17:09:15 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "ft_printf.h"

# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>


# define WIN_WIDTH 800
# define WIN_HEIGHT 600

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
    int         endian;
    int         height;
    int         width;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win;
	t_img		img;
}				t_mlx;

typedef struct	s_map
{
	int		resolution_w;
	int		resolution_h;
	char	*texture_nord;
	char	*texture_sud;
	char	*texture_ouest;
	char	*texture_est;
	char	*texture_sprite;
	int		couleur_plafond;
	int		couleur_sol;
	char	*mapinit;
	char	**map;
	int		map_w;
	int		map_h;
	void	(*ft_parse_cub[9])(char *str, struct s_map *carte);
	char	tabindex[9];
}				t_map;

#endif