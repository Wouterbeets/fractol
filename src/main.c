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
# include "../minilibx_macos/mlx.h"
#include <stdio.h>

int		key_hook(int keycode, t_mlx *e)
{
	(void)e;
	printf("%d\n", keycode);
	if (keycode == 53)
		exit(0);
	return (0);
}

int		expose_hook(t_mlx *mlx)
{
	(void)mlx;
	draw(mlx);
	return (0);
}

int		check_args(char** av)
{
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		return (0);
	if (ft_strcmp(av[1], "foo") == 0)
		return (1);
	if (ft_strcmp(av[1], "julia") == 0)
		return (2);
	return (3);
}

int main(int ac, char ** av)
{
	t_mlx	mlx;
	void	(*func_tab[4]) (t_fract *, double, double);
	func_tab[0] = &mandelbrot;
	func_tab[1] = 0;
	func_tab[2] = &julia;
	func_tab[3] = 0;
	if (ac == 2 && (mlx.func = func_tab[check_args(av)]) != 0)
	{
		mlx.mlx = mlx_init();
		mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "fractol wbeets");
		mlx.img = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
		mlx_key_hook(mlx.win, key_hook, &mlx);
		mlx_expose_hook(mlx.win, expose_hook, &mlx);
		mlx_loop(mlx.mlx);
		(void)av;
	}
	else 
		ft_putstr("USAGE: ./fractole -[madelbrot, julia, foo]");
	return (0);
}
