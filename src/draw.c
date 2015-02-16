
#include "../includes/header.h"
//# include "../minilibx_macos/mlx.h"
#include <mlx.h>
#include <stdio.h>
//
//int		pixel_to_image(t_mlx *mlx, int x, int y, int c)
//{
//	int	octets;
//
//	octets = mlx->bpp / 8;
//	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
//		ft_memcpy(&mlx->data[octets * (x * octets + ((mlx->size_line / octets) * y))]
//					, &c, octets);
//	return (0);
//}

int			pixel_to_image(t_mlx *mlx, int x, int y, int c)
{
	int offset;

	c = BLUE * c;
	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
//		printf("x = %d\t, y = %d\t c = %d\t mlx->line_size = %d\n", x, y, c, mlx->size_line);
		offset = (y * WIDTH	+ x) * mlx->bypp;
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
	calc->p_real = 1.5 * (x - w / 2) / (0.5 * calc->zoom * w) + calc->move_x;
	calc->p_imag = (y - h /(double)2) / (0.5 * calc->zoom * h) + calc->move_y;
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
	while (y < WIDTH)
	{
		while (x < HEIGHT)
		{
			mlx->func(mlx->calc, x, y);
			//	mlx_pixel_put(mlx->mlx, mlx->win, x, y, BLUE * mlx->calc->color);
			pixel_to_image(mlx, x, y,  mlx->calc->color);
			x++;
		}
		y++;
		x = 0;
	}
	ft_putstr("before img to window");
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0 ,0);
}
