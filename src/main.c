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
# include <mlx.h>

int		key_hook(int keycode, t_mlx *e)
{
	(void)e;
	if (keycode == 65307)
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
		return (1);
	if (ft_strcmp(av[1], "foo") == 0)
		return (2);
	if (ft_strcmp(av[1], "julia") == 0)
		return (3);
	return (FALSE);
}

int main(int ac, char ** av)
{
	t_mlx	mlx;

	if (ac == 2 && check_args(av))
	{
		mlx.mlx = mlx_init();
		mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "fractol wbeets");
		mlx_key_hook(mlx.win, key_hook, &mlx);
		mlx.av = av;
		mlx_expose_hook(mlx.win, expose_hook, &mlx);
		mlx_loop(mlx.mlx);
		(void)av;
	}
	else 
	{
		ft_putstr("USAGE: ./fractole -[madelbrot, julia, foo]");
	}
	return (0);
}
