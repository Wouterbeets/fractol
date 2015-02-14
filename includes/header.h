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
# include "../minilibx_macos/mlx.h"
# include <stdlib.h>

# define TRUE		1
# define FALSE		0
# define WIDTH		800
# define HEIGHT		800

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
}					t_fract;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			(*func)(t_fract *, double, double);
	t_fract			*calc;
	void			*img;
}					t_mlx;

void	draw(t_mlx *mlx);
void	julia(t_fract *calc, double x, double y);
void	mandelbrot(t_fract *calc, double x, double y);

#endif /* HEADER_H */
