/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeets <wbeets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 21:23:21 by wbeets            #+#    #+#             */
/*   Updated: 2013/12/22 21:26:46 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../libft/includes/libft.h"
# include "../includes/mlx_bindings.h"
//# include "../minilibx_macos/mlx.h"
# include <stdlib.h>

# define TRUE		1
# define FALSE		0
# define WIDTH		800
# define HEIGHT		800
# define ZOOM_STEP	1.05

# define WHITE 0xFFFFFF
# define GREY 0x555555
# define BLACK 0x111111
# define VIOLET 0xB545AE
# define BLUE 0x6692CC
# define GREEN 0x81CC66
# define ORANGE 0xED6205
# define MAX_IT mlx->calc->iterations

typedef struct		s_complex
{
	double			a;
	double			b;
}					t_complex;

typedef struct		s_fract
{
	double			c_real;
	double			c_imag;
	double			new_real;
	double			new_imag;
	double			old_real;
	double			old_imag;
	double			zoom;
	double			move_x;
	double			move_y;
	int				color;
	int				iterations;
	double			p_real;
	double			p_imag;
	double			newtond;
}					t_fract;

typedef struct		s_mlx
{
	int				redraw;
	void			*mlx;
	void			*win;
	void			(*func)(t_fract *, double, double);
	t_fract			*calc;
	void			*img;
	char			*data;
	int				bw;
	int				bpp;	
	int				bypp;	
	int				size_line;
	int				endian;
	int				old_mouse_x;
	int				old_mouse_y;
}					t_mlx;
/*fractals*/
void	draw(t_mlx *mlx);
void	julia(t_fract *calc, double x, double y);
void	mandelbrot(t_fract *calc, double x, double y);
void	newton(t_fract *calc, double x, double y);
void	init_frac(t_fract *calc);
void	(*get_fractal_func(char **av))(t_fract *, double, double);
int		zoom(int x, int y, double zoom, t_mlx *mlx);

/*hooks*/
int		key_hook(int keycode, t_mlx *mlx);
int		expose_hook(t_mlx *mlx);
int		check_args(char** av);
int		loop_hook(t_mlx *mlx);
int		mouse_button_hook(int button, int x, int y, t_mlx *mlx);
int		mouse_motion_hook(int x, int y, t_mlx *mlx);

/*complex functions*/
t_complex	complex_calc(t_complex c1, t_complex c2, char op);
t_complex	complex_power(t_complex c1, unsigned int n);
t_complex	complex_new(double aa, double bb);
double		complex_dist(t_complex c1, t_complex c2);
double		complex_norm(t_complex c);

#endif /* HEADER_H */
