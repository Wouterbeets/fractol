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
# include <mlx.h>
# include <stdlib.h>

# define TRUE		1
# define FALSE		0
# define WIDTH		720
# define HEIGHT		720

# define WHITE 0xFFFFFF
# define GREY 0x555555
# define VIOLET 0xB545AE
# define BLUE 0x6692CC
# define GREEN 0x81CC66
# define ORANGE 0xED6205


typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	char			**av;
}					t_mlx;


void	draw(t_mlx *mlx);

#endif /* HEADER_H */
