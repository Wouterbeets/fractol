

#include "../includes/header.h"
//# include "../minilibx_macos/mlx.h"
#include <mlx.h>
#include <stdio.h>

int			pixel_to_image(t_mlx *mlx, int x, int y, int c)
{
	int offset;
	float color;

	color =  (float)c / (float)mlx->calc->iterations;
	offset = (y * WIDTH	+ x) * mlx->bypp;
	if (mlx->bw)
	{
		mlx->data[offset] = c < MAX_IT ? color * 255 : 0;
		mlx->data[offset + 1] = c < MAX_IT ? color * 255 : 0;
		mlx->data[offset + 2] = c < MAX_IT ? color * 255 : 0;
	}
	else
	{
		c = c < MAX_IT ? c * BLUE : 0x111111;
		ft_memmove(mlx->data + offset, &c, mlx->bypp);
	}
	return (0);
}


void	julia(t_fract *calc, double x, double y)
{
	int		i;
	double  w;
	double	h;

	w = WIDTH;
	h = HEIGHT;

	i = 0;
	calc->new_real = 1.5 * (x - w /(double)2) / (calc->zoom * w) + calc->move_x;
	calc->new_imag = (y - h /(double)2) / (calc->zoom * h) + calc->move_y;
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
	calc->p_real = 1.5 * (x - w / 2) / (1 * calc->zoom * w) + calc->move_x;
	calc->p_imag = (y - h /(double)2) / (1 * calc->zoom * h) + calc->move_y;
	calc->new_real = calc->new_imag = calc->old_real = calc->old_imag = 0;
	while (i < calc->iterations)
	{
		calc->old_real = calc->new_real;
		calc->old_imag = calc->new_imag;
		calc->new_real = calc->old_real * calc->old_real - calc->old_imag * calc->old_imag + calc->p_real;
		calc->new_imag = 2.0 * calc->old_real * calc->old_imag + calc->p_imag + calc->p_imag;
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

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			mlx->func(mlx->calc, x, y);
			pixel_to_image(mlx, x, y, mlx->calc->color);
			x++;
		}
		y++;
		x = 0;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0 ,0);
}
