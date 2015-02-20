/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 09:53:44 by wbeets            #+#    #+#             */
/*   Updated: 2015/02/12 09:53:46 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/header.h"
//# include "../minilibx_macos/mlx.h"
#include <mlx.h>
#include "/usr/X11/include/X11/X.h"

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
	calc->move_y = 0;
	calc->color = BLUE;
	calc->iterations = 30;
	calc->p_real = 0;
	calc->p_imag = 0;
}

int		init_mlx(t_mlx *mlx, int ac, char **av)
{
	if (ac == 2 && (mlx->func = get_fractal_func(av)) != 0)
	{
		mlx->mlx = mlx_init();
		mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "fractol wbeets");
		mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
		mlx->data = mlx_get_data_addr(mlx->img, &(mlx->bpp), &(mlx->size_line), &(mlx->endian)); 
		mlx->bypp = mlx->bpp / 8;
		mlx_loop_hook(mlx->mlx, loop_hook, mlx);
		mlx_hook(mlx->win, Expose, ExposureMask, expose_hook, mlx);
		mlx_hook(mlx->win, KeyPress, KeyPressMask, key_hook, mlx);
		mlx_hook(mlx->win, ButtonPress, ButtonPressMask, mouse_button_hook, mlx);
		mlx_hook(mlx->win, MotionNotify, PointerMotionMask, mouse_motion_hook, mlx);
		mlx->old_mouse_x = -1;
		mlx->old_mouse_y = -1;
		return (1);
	}
	return (0);
}

int		main(int ac, char ** av)
{
	t_mlx	mlx;
	t_fract	calc;

	init_frac(&calc);
	mlx.calc = &calc;
	mlx.mlx = 0;
	if (init_mlx(&mlx, ac, av))
		mlx_loop(mlx.mlx);
	else 
		ft_putstr("USAGE: ./fractole -[madelbrot, julia, foo]");
	return (0);
}
