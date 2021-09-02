/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 18:57:39 by vcavalca          #+#    #+#             */
/*   Updated: 2021/09/02 19:07:10 by vcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_init_complex(t_complex *c, double a, double b)
{
	c->x = a;
	c->y = b;
}

void	ft_add_complex(t_complex *c, t_complex a, t_complex b)
{
	c->x = a.x + b.x;
	c->y = a.y + a.y;
}

void	ft_sqr_complex(t_complex *c, t_complex a)
{
	c->x = (a.x * a.x) - (a.y * a.y);
	c->y = 2 * a.x * a.y;
}

double	ft_mod_complex(t_complex a)
{
	return ((a.x * a.x + a.y * a.y));
}

void	ft_map_point(t_fractol *fractol, t_complex *c, int x, int y)
{
	c->x = (x / (double)REDUCED_SCALE + fractol->side) / fractol->mag;
	c->y = (y / (double)REDUCED_SCALE + fractol->vert) / fractol->mag;
}
