
#include "../includes/header.h"

void	draw(t_mlx *mlx)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		while (y < HEIGHT)
		{
			mlx_pixel_put(mlx->mlx, mlx->win, y, x, WHITE);
			y++;
		}
		x++;
		y = 0;
	}
}
