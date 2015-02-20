
#include "../includes/header.h"

int		expose_hook(t_mlx *mlx)
{
	(void)mlx;
	draw(mlx);
	return (0);
}

int		key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == KEYCODE_RIGHT)
		mlx->calc->move_x += 0.01;
	else if (keycode == KEYCODE_LEFT)
		mlx->calc->move_x -= 0.01;
	else if (keycode == KEYCODE_UP)
		mlx->calc->move_y -= 0.01;
	else if (keycode == KEYCODE_DOWN)
		mlx->calc->move_y += 0.01;
	else if (keycode == KEYCODE_PAVNUM_MINUS)
		mlx->calc->iterations--;
	else if (keycode == KEYCODE_C)
		mlx->bw = mlx->bw == 1 ? 0 : 1;
	else if (keycode == KEYCODE_PAVNUM_PLUS)
	{
		mlx->calc->iterations++;
		ft_putstr("it = ");
		ft_putnbr(MAX_IT);
		ft_putstr("\n");
	}
	else if (keycode == KEYCODE_ECHAP)
		exit(0);
	bzero(mlx->data, WIDTH * HEIGHT * mlx->bypp);
	mlx->redraw = 1;
	return (0);
}

int		loop_hook(t_mlx *mlx)
{
	if (mlx->redraw == 1)
		draw(mlx);
	mlx->redraw = 0;
	return (0);
}

int		check_args(char** av)
{
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		return (0);
	if (ft_strcmp(av[1], "newton") == 0)
		return (1);
	if (ft_strcmp(av[1], "julia") == 0)
		return (2);
	return (3);
}

void	(*get_fractal_func(char **av))(t_fract *, double, double) 
{
	int		func;

	func = check_args(av);
	if (func == 0)
		return (&mandelbrot);
	if (func == 1)
		return 0;
	if (func == 2)
		return (&julia);
	if (func == 3)
		return 0;
	return 0;
}
