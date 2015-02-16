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
# define WIDTH		600
# define HEIGHT		600

# define WHITE 0xFFFFFF
# define GREY 0x555555
# define VIOLET 0xB545AE
# define BLUE 0x6692CC
# define GREEN 0x81CC66
# define ORANGE 0xED6205

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
}					t_fract;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			(*func)(t_fract *, double, double);
	t_fract			*calc;
	void			*img;
	char			*data;
	int				bpp;	
	int				bypp;	
	int				size_line;
	int				endian;
}					t_mlx;

void	draw(t_mlx *mlx);
void	julia(t_fract *calc, double x, double y);
void	mandelbrot(t_fract *calc, double x, double y);
void	init_frac(t_fract *calc);
int		key_hook(int keycode, t_mlx *e);
int		expose_hook(t_mlx *mlx);
int		check_args(char** av);
void	(*get_fractal_func(char **av))(t_fract *, double, double);
int		loop_hook(t_mlx *mlx);

#endif /* HEADER_H */
