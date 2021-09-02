/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:49:23 by vcavalca          #+#    #+#             */
/*   Updated: 2021/09/02 20:16:47 by vcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_julia(t_fractol *fractol, int ix, int iy)
{
	t_complex	c;
	t_complex	z0;
	t_complex	z1;
	int			i;

	if (fractol->type == JULIA_MOUSE)
		ft_map_point(fractol, &c, fractol->x_mouse, fractol->y_mouse);
	else
		ft_init_complex(&c, fractol->x_param, fractol->y_param);
	ft_map_point(fractol, &z0, ix, iy);
	i = 0;
	while (++i < fractol->max_i)
	{
		ft_sqr_complex(&z0, z0);
		ft_add_complex(&z1, z0, c);
		if (ft_mod_complex(z1) > DIV_VALUE * DIV_VALUE)
			break ;
		z0 = z1;
	}
	return (ft_create_trgb(fractol, i));
}
