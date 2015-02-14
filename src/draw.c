
#include "../includes/header.h"
# include "../minilibx_macos/mlx.h"
#include <stdio.h>

void	init_frac(t_fract *calc)
{
	calc->c_real = -0.7;
	calc->c_imag = 0.27015;
	calc->new_real = 0;
	calc->new_imag = 0;
	calc->old_real = 0;
	calc->new_real = 0;
	calc->zoom = 2;
	calc->move_x = 0;
	calc->move_y = 0;
	calc->color = BLUE;
	calc->iterations = 300;
}

void	julia(t_fract *calc, double x, double y)
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

void	mandelbrot(t_fract *calc, double x, double y)
{
	int		i;
	double  w;
	double	h;
	
	i = 0;
	w = WIDTH;
	h = HEIGHT;
	calc->c_real = 1.5 * (x - w / 2) / (0.5 * calc->zoom * w) + calc->move_x;
	calc->c_imag = (y - h /(double)2) / (0.5 * calc->zoom * h) + calc->move_y;
	calc->new_real = calc->new_imag = calc->old_real = calc->old_imag = 0;
	while (i < calc->iterations)
	{
		calc->old_real = calc->new_real;
		calc->old_imag = calc->new_imag;
		calc->new_real = calc->old_real * calc->old_real - calc->old_imag * calc->old_imag + calc->c_real;
		calc->new_imag = 2.0 * calc->old_real * calc->old_imag + calc->c_imag + calc->c_imag;
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
				mlx->func(&calc, x, y);
				mlx_pixel_put(mlx->mlx, mlx->win, x, y, BLUE * calc.color);
			y++;
		}
		x++;
		y = 0;
	}
}
