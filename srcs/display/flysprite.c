t_bool	draw_sprite(t_sprite sp, t_img img, t_mlx *mlx)
{
	t_fromto	sprite;
	t_vect_int	screen;
	t_vect_int	print;
	t_vect_int	getpix;
	int color;

	(void)mlx;
	(void)sp;
	sprite.from = 0;
	sprite.to = img.width;
	if (sp.r_before.distance < sp.dist)
		sprite.from = ft_abs((sp.fst_hit.x - (int)sp.fst_hit.x) * img.width);
	if (sp.r_after.distance < sp.dist)
		sprite.to = ft_abs((int)sp.last_hit.x + 1 - sp.last_hit.x * img.width);
	screen.y = mlx->map->r_height * 0.5 - mlx->map->r_height / sp.dist * 0.5;
	screen.x = (tan(degrees_to_radian(60) - sp.r_before.angle) * sp.dist) *mlx->map->tile;
	getpix.y = 0;
	// printf("sprite from %d\nsprite to %d\nx %d | y %d\nimgheigt %d\n\n", sprite.from, sprite.to,x,y, img.height);
	while (getpix.y < img.height)
	{
		getpix.x = sprite.from;
		print.x = screen.x;
		while (getpix.x < sprite.to)
		{
			if ((color = ft_pixel_get_color(img, getpix.x, getpix.y)) > 0)
				ft_pixel_put(mlx, print.x, screen.y, color );
			getpix.x++;
			print.x++;
		}
		screen.y++;
		getpix.y++;
	}
	// printf("sprite from %d\nsprite to %d\nx %d | y %d\nimgheigt %d\n\n", sprite.from, sprite.to,x,y, img.height);
	return (True);
}