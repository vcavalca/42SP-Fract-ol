/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 17:55:52 by vcavalca          #+#    #+#             */
/*   Updated: 2021/08/31 20:35:02 by vcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_mlx_pixel_put(t_img_data	*img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x *(img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
