/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 12:30:40 by vcavalca          #+#    #+#             */
/*   Updated: 2021/08/31 17:59:31 by vcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"

/*window size*/
# define WIN_X 1024
# define WIN_Y 768

/*Struct IMG*/
typedef struct s_img_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_img_data;

/*Struct MLX*/
typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}t_mlx;

void	my_mlx_pixel_put(t_img_data	*img, int x, int y, int color);

#endif
