/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 12:30:40 by vcavalca          #+#    #+#             */
/*   Updated: 2021/09/07 08:17:38 by vcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include "libft/incl/libft.h"
# include "minilibx-linux/mlx.h"

# define SCREEN_X 1024
# define SCREEN_Y 768

/*Struct MLX*/
typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	double	c_r;
	double	c_i;
	void	*img_ptr;
	int		*img_data;
	int		img_line_length;
	int		img_bpp;
	int		img_endian;
	int		data_x;
	int		data_y;
	float	data_x1;
	float	data_y1;
	float	data_zoom;
	float	data_iteration_max;
	float	data_image_x;
	float	data_image_y;
	float	data_tmp;
}t_mlx;

double	ft_fmt_param(char *str);
double	ft_fmt_number(char *str, double res);

int		ft_julia_param(double cr, double ci, int if_param, t_mlx *mlx);
int		ft_close_button(t_mlx *mlx);
int		ft_esc_button(int key_code, t_mlx *mlx);

void	ft_mandelbrot(void);
void	ft_julia(double cr, double ci, int if_param);
void	browse_julia(t_mlx *mlx);

#endif
