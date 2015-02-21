/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousehook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 09:49:20 by wbeets            #+#    #+#             */
/*   Updated: 2015/02/21 09:49:22 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx_bindings.h"
#include "../includes/header.h"

int		zoom(int x, int y, double zoom, t_mlx *mlx)
{
	double move_x;
	double move_y;

	mlx->calc->zoom *= zoom;
	move_x = ((double)x - (WIDTH / 2.0)) / (WIDTH / 2);
	move_y = ((double)y - (HEIGHT / 2.0)) / (HEIGHT / 2);
	mlx->calc->move_x += move_x / mlx->calc->zoom / 10;
	mlx->calc->move_y += move_y / mlx->calc->zoom / 10;
	return (1);
}

int		mouse_button_hook(int button, int x, int y, t_mlx *mlx)
{
	mlx->redraw = 1;
	if (button == MOUSE_WHEEL_UP)
		return (zoom(x, y, ZOOM_STEP, mlx));
	else if (button == MOUSE_WHEEL_DOWN)
		return (zoom(x, y, 0.9, mlx));
	mlx->redraw = 0;
	return (0);
}

int		mouse_motion_hook(int x, int y, t_mlx *mlx)
{
	if (mlx->old_mouse_x != -1 && mlx->func == julia)
	{
		mlx->calc->c_real += ((double)mlx->old_mouse_y - (double)y) / 300.0;
		mlx->calc->c_imag += ((double)mlx->old_mouse_x - (double)x) / 300.0;
		mlx->redraw = 1;
	}
	mlx->old_mouse_x = x;
	mlx->old_mouse_y = y;
	return (0);
}
