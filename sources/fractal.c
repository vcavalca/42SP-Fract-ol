/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 18:46:11 by vcavalca          #+#    #+#             */
/*   Updated: 2021/09/02 20:25:06 by vcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_create_trgb(t_fractol *fractol, int i)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = 0;
	if (i == fractol->max_i)
	{
		r = 0;
		g = 0;
		b = 0;
	}
	else
	{
		r = sin(0.6 * i + 0) * 127 + 128 + fractol->color;
		g = sin(0.6 * i + 2 * M_PI / 3) * 127 + 128 + fractol->color;
		b = sin(0.6 * i + 4 * M_PI / 3) * 127 + 128 + fractol->color;
	}
	return (t << 24 | r << 16 | g << 8 | b);
}

void	ft_fractal(t_fractol *fractol)
{
	int	ix;
	int	iy;
	int	color;

	mlx_clear_window(fractol->mlx, fractol->mlx_win);
	iy = -1;
	while (++iy < SCREEN_Y)
	{
		ix = -1;
		while (++ix < SCREEN_X)
		{
			if (fractol->type == MANDELBROT)
				color = ft_mandelbrot(fractol, ix, iy);
			else if (fractol->type == JULIA_MOUSE)
				color = ft_julia(fractol, ix, iy);
			else if (fractol->type == JULIA_PARAM)
				color = ft_julia(fractol, ix, iy);
			else if (fractol->type == BURNINGSHIP)
				color = ft_burning_ship(fractol, ix, iy);
			my_mlx_pixel_put(fractol, ix, iy, color);
		}
	}
	mlx_put_image_to_window(fractol->mlx, fractol->mlx_win, fractol->img, 0, 0);
}
