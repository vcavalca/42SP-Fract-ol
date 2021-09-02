/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 19:48:46 by vcavalca          #+#    #+#             */
/*   Updated: 2021/09/02 20:08:42 by vcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_mouse_hook(int x, int y, t_fractol *fractol)
{
	fractol->x_mouse = x;
	fractol->y_mouse = y;
	ft_fractal(fractol);
	return (0);
}

int	ft_key_hook(int keycode, t_fractol *fractol)
{
	if (keycode == KEY_ESC)
	{
		ft_free_mlx(fractol);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == KEY_UP)
		fractol->vert -= MOVE_DIST;
	else if (keycode == KEY_DOWN)
		fractol->vert += MOVE_DIST;
	else if (keycode == KEY_LEFT)
		fractol->side -= MOVE_DIST;
	else if (keycode == KEY_RIGHT)
		fractol->side += MOVE_DIST;
	else if (keycode == KEY_A && fractol->color >= COLOR_CHANGE)
		fractol->color -= COLOR_CHANGE;
	else if (keycode == KEY_D && fractol->color <= COLOR_MAX)
		fractol->color += COLOR_CHANGE;
	else if (keycode == KEY_S && fractol->max_i > INIT_IMAX)
		fractol->max_i -= CHANGE_IMAX;
	else if (keycode == KEY_W && fractol->max_i < MAX_IMAX)
		fractol->max_i += CHANGE_IMAX;
	ft_fractal(fractol);
	return (0);
}

int	ft_mouse_click(int button, int x, int y, t_fractol *fractol)
{
	t_complex	c;
	double		n;

	ft_map_point(fractol, &c, x, y);
	n = 0.0;
	if (button == KEY_SCROLLUP)
	{
		n = fractol->mag * MAGNIFICATION;
		fractol->mag += n;
		fractol->side -= n * c.x / ((double)SCREEN_X * fractol->mag) - n * c.x;
		fractol->vert -= n * c.y / ((double)SCREEN_Y * fractol->mag) - n * c.y;
	}
	else if (button == KEY_SCROLLDOWN)
	{
		if (fractol->mag > 0.1)
			n = fractol->mag * MAGNIFICATION;
		fractol->mag -= n;
		fractol->side += n * c.x / ((double)SCREEN_X * fractol->mag) - n * c.x;
		fractol->vert += n * c.y / ((double)SCREEN_Y * fractol->mag) - n * c.y;
	}
	if (button != KEY_SCROLLDOWN && button != KEY_SCROLLLEFT
		&& button != KEY_SCROLLRIGHT)
		printf("(%f,%f)\n", c.x, c.y);
	ft_fractal(fractol);
	return (0);
}

int	ft_cross_button(t_fractol *fractol)
{
	ft_free_mlx(fractol);
	exit(EXIT_SUCCESS);
	return (0);
}
