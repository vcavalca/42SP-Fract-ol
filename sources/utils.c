/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 17:55:52 by vcavalca          #+#    #+#             */
/*   Updated: 2021/09/02 18:54:44 by vcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_strcmp_f(const char *s1, const char *s2)
{
	int	i;

	if (ft_strlen(s1) != ft_strlen(s2))
		return (1);
	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

double	ft_atof(char *s)
{
	double	sign;
	double	n;
	double	i;

	sign = 1;
	n = 0;
	i = 1;
	if (*s == '+')
		s++;
	else if (*s == '-')
	{
		s++;
		sign = -1;
	}
	while (ft_isdigit(*s))
	{
		n = n * 10 + *s - '0';
		s++;
	}
	if (*s == '.')
	{
		while (ft_isdigit(*++s))
			n += (*s - '0') * (i *= 0.1);
	}
	return (n * sign);
}

void	ft_free_mlx(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->img);
	mlx_destroy_window(fractol->mlx, fractol->mlx_win);
	mlx_destroy_display(fractol->mlx);
	free(fractol->mlx);
}

void	ft_error_print(void)
{
	ft_putstr("Please, Give a number as an argument");
	ft_putstr("\n");
	ft_putstr(NULL);
	ft_putstr("You can specify from 1 to 4 fractals");
	ft_putstr("\n");
	ft_putstr(NULL);
	ft_putstr("List of available fractals:");
	ft_putstr("\n");
	ft_putstr("1 : Mandelbrot");
	ft_putstr("\n");
	ft_putstr("2 : Julia with mouse coordinate");
	ft_putstr("\n");
	ft_putstr("3 : Julia with params");
	ft_putstr("\n");
	ft_putstr("4 : Burning Ship");
	ft_putstr("\n\n");
}

void	my_mlx_pixel_put(t_fractol *fractol, int x, int y, int color)
{
	char	*dst;

	dst = fractol->addr + (y * fractol->size_line
			+ x * (fractol->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
