/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 09:48:49 by wbeets            #+#    #+#             */
/*   Updated: 2015/02/21 09:48:52 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"
#include <mlx.h>
#include <stdio.h>

void	newton(t_fract *calc, double x, double y)
{
	int		i;
	double	temp;

	i = 0;
	calc->new_real = 1.5 * (x - (double)WIDTH / (double)2)
		/ (calc->zoom * (double)WIDTH) + calc->move_x;
	calc->new_imag = (y - (double)HEIGHT / (double)2)
		/ (calc->zoom * (double)HEIGHT) + calc->move_y;
	while (i < calc->iterations)
	{
		calc->c_real = calc->new_real * calc->new_real;
		calc->c_imag = calc->new_imag * calc->new_imag;
		calc->newtond = 3.0 * ((calc->c_real - calc->c_imag) *
			(calc->c_real - calc->c_imag) + 4.0 * calc->c_real * calc->c_imag);
		if (calc->newtond == 0.0)
			calc->newtond = 0.000001;
		temp = calc->new_real;
		calc->new_real = (2.0 / 3.0) * calc->new_real +
			(calc->c_real - calc->c_imag) / calc->newtond;
		calc->new_imag = (2.0 / 3.0) * calc->new_imag - 2.0 *
			temp * calc->new_imag / calc->newtond;
		i++;
	}
	calc->color = get_color(calc->new_real, calc->new_imag, calc->iterations);
}

void	julia(t_fract *calc, double x, double y)
{
	int		i;
	double	w;
	double	h;

	w = WIDTH;
	h = HEIGHT;
	i = 0;
	calc->new_real = 1.5 * (x - w / 2) / (calc->zoom * w) + calc->move_x;
	calc->new_imag = (y - h / 2) / (calc->zoom * h) + calc->move_y;
	while (i < calc->iterations)
	{
		calc->old_real = calc->new_real;
		calc->old_imag = calc->new_imag;
		calc->new_real = calc->old_real * calc->old_real - calc->old_imag
			* calc->old_imag + calc->c_real;
		calc->new_imag = 2.0 * calc->old_real * calc->old_imag + calc->c_imag;
		if ((calc->new_real * calc->new_real +
					calc->new_imag * calc->new_imag) > 4)
			break ;
		i++;
	}
	calc->color = i;
}

void	set_to_zero(double *nri, double *nim, double *ore, double *oim)
{
	*nri = 0;
	*nim = 0;
	*ore = 0;
	*oim = 0;
}

void	mandelbrot(t_fract *c, double x, double y)
{
	int		i;
	double	w;
	double	h;

	i = 0;
	w = WIDTH;
	h = HEIGHT;
	c->p_real = 1.5 * (x - w / 2) / (1 * c->zoom * w) + c->move_x;
	c->p_imag = (y - h / 2) / (1 * c->zoom * h) + c->move_y;
	set_to_zero(&c->new_real, &c->new_imag, &c->old_real, &c->old_imag);
	while (i < c->iterations)
	{
		c->old_real = c->new_real;
		c->old_imag = c->new_imag;
		c->new_real = c->old_real * c->old_real - c->old_imag
			* c->old_imag + c->p_real;
		c->new_imag = 2.0 * c->old_real * c->old_imag
			+ c->p_imag + c->p_imag;
		if ((c->new_real * c->new_real +
					c->new_imag * c->new_imag) > 4)
			break ;
		i++;
	}
	c->color = i;
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
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
