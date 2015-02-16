
#include "../includes/header.h"

int		expose_hook(t_mlx *mlx)
{
	(void)mlx;
	draw(mlx);
	return (0);
}

int		key_hook(int keycode, t_mlx *e)
{
	(void)e;
	if (keycode == 123)
		e->calc->move_x -= 0.01;
	else if (keycode == 124)
		e->calc->move_x += 0.01;
	else if (keycode == 125)
		e->calc->move_y -= 0.01;
	else if (keycode == 126)
		e->calc->move_y += 0.01;
	else if (keycode == 53)
		exit(0);
	draw(e);
	return (0);
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
