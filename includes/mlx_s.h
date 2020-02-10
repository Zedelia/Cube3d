/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mlx_s.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mbos <mbos@student.le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/25 11:24:42 by mbos         #+#   ##    ##    #+#       */
/*   Updated: 2020/02/10 18:24:26 by mbos        ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MLX_S_H
# define MLX_S_H

# include "cube3d.h"

t_bool		mlx_ft_init(t_mlx **mlx, char *file);
void		mlx_free(t_mlx *mlx);

t_bool		img_load_xpm(t_mlx *mlx, char *file, t_img *img);
t_bool		img_display(t_mlx *mlx, t_img *img);

void		cam_printf(t_cam *cam);
t_bool		cam_init(t_mlx *mlx);
void		cam_get_rotation_angle(t_cam *cam);
void		cam_get_pos(t_cam *cam, t_map *map);

int			move_keydown(int key, t_mlx *mlx);
t_bool		move_apply(t_move *move, t_mlx *mlx);

#endif
