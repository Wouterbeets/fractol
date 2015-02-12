
#include "../includes/header.h"
#include <stdio.h>

void	init_frac(t_fract *calc)
{
	calc->c_real = -0.7;
	calc->c_imag = 0.27015;
	calc->new_real = 0;
	calc->new_imag = 0;
	calc->old_real = 0;
	calc->new_real = 0;
	calc->zoom = 1;
	calc->move_x = 0;
	calc->move_x = 0;
	calc->color = BLUE;
	calc->iterations = 300;
}

void	calc_pixel(t_fract *calc, double x, double y)
{
	int		i;
	double  w;
	double	h;

	w = WIDTH;
	h = HEIGHT;

	i = 0;
	calc->new_real = 1.5 * (x - w /(double)2) / (0.5 * calc->zoom * w) + calc->move_x;
	calc->new_imag = (y - h /(double)2) / (0.5 * calc->zoom * h) + calc->move_y;
	while (i < calc->iterations)
	{
		calc->old_real = calc->new_real;
		calc->old_imag = calc->new_imag;
		calc->new_real = calc->old_real * calc->old_real - calc->old_imag * calc->old_imag;
		calc->new_imag = 2.0 * calc->old_real * calc->old_imag + calc->c_imag;
		
		if ((calc->new_real * calc->new_real + calc->new_imag * calc->new_imag) > 4)
			break;
		i++;
	}
	calc->color = i;
}

void	draw(t_mlx *mlx)
{
	double		x;
	double		y;
	t_fract	calc;

	x = 0;
	y = 0;
	init_frac(&calc);
	while (x < WIDTH)
	{
		while (y < HEIGHT)
		{
			calc_pixel(&calc, x, y);
			mlx_pixel_put(mlx->mlx, mlx->win, x, y, BLUE * calc.color);
			y++;
		}
		x++;
		y = 0;
	}
}
