/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_burning_ship.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:54:17 by vcavalca          #+#    #+#             */
/*   Updated: 2021/09/02 20:17:35 by vcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_burning_ship(t_fractol *fractol, int ix, int iy)
{
	t_complex	c;
	t_complex	z0;
	t_complex	z1;
	int			i;

	ft_map_point(fractol, &c, ix, iy);
	ft_init_complex(&z0, 0.0, 0.0);
	ft_init_complex(&z1, 0.0, 0.0);
	i = 0;
	while (++i < fractol->max_i)
	{
		ft_sqr_complex(&z0, z0);
		ft_add_complex(&z1, z0, c);
		if (ft_mod_complex(z1) > DIV_VALUE * DIV_VALUE)
			break ;
		z0.x = fabs(z1.x);
		z1.y = fabs(z1.y);
	}
	return (ft_create_trgb(fractol, i));
}
