/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 16:48:39 by vcavalca          #+#    #+#             */
/*   Updated: 2021/09/21 07:12:34 by vcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ft_calcul_mandelbrot(t_mlx *mlx)
{
	float	c_r;
	float	c_i;
	float	z_r;
	float	z_i;
	float	i;

	c_i = mlx->data_y / mlx->data_zoom + mlx->data_y1;
	c_r = mlx->data_x / mlx->data_zoom + mlx->data_x1;
	z_r = 0;
	z_i = 0;
	i = 0;
	while (((z_r * z_r) + (z_i * z_i) < 4) && (i < mlx->data_iteration_max))
	{
		mlx->data_tmp = z_r;
		z_r = ((z_r * z_r) - (z_i * z_i)) + c_r;
		z_i = ((2 * z_i) * mlx->data_tmp) + c_i;
		i++;
	}
	if (i == mlx->data_iteration_max)
		mlx->img_data[(mlx->x * mlx->data_y) + mlx->data_x] = 0x00000000;
	else
		mlx->img_data[(mlx->x * mlx->data_y) + mlx->data_x] = 0x000B00EF * i;
}

static void	ft_browse_mandelbrot(t_mlx *mlx)
{
	mlx->img_ptr = NULL;
	mlx->img_ptr = mlx_new_image(mlx->mlx, mlx->x, mlx->y);
	if (mlx->img_ptr == NULL)
		return ;
	mlx->img_data = (int *)mlx_get_data_addr(mlx->img_ptr, &mlx->img_bpp,
			&mlx->img_line_length, &mlx->img_endian);
	while (mlx->data_x < mlx->data_image_x)
	{
		mlx->data_y = 0;
		while (mlx->data_y < mlx->data_image_y)
		{
			ft_calcul_mandelbrot(mlx);
			mlx->data_y++;
		}
		mlx->data_x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img_ptr, 0, 0);
	mlx_destroy_image(mlx->mlx, mlx->img_ptr);
}

static int	ft_zoom(int keycode, int x, int y, t_mlx *mlx)
{
	if (keycode == 4)
	{
		mlx->data_x = 0;
		mlx->data_y = 0;
		mlx->data_x1 = (x / mlx->data_zoom + mlx->data_x1)
			- (x / (mlx->data_zoom * 1.3));
		mlx->data_y1 = (y / mlx->data_zoom + mlx->data_y1)
			- (y / (mlx->data_zoom * 1.3));
		mlx->data_zoom *= 1.3;
		mlx->data_iteration_max++;
		ft_browse_mandelbrot(mlx);
	}
	if (keycode == 5)
	{
		mlx->data_x = 0;
		mlx->data_y = 0;
		mlx->data_x1 = (x / mlx->data_zoom + mlx->data_x1)
			- (x / (mlx->data_zoom / 1.3));
		mlx->data_y1 = (y / mlx->data_zoom + mlx->data_y1)
			- (y / (mlx->data_zoom / 1.3));
		mlx->data_zoom /= 1.3;
		mlx->data_iteration_max--;
		ft_browse_mandelbrot(mlx);
	}
	return (0);
}

static void	ft_initialise(t_mlx *mlx)
{
	mlx->data_zoom = 250;
	mlx->data_x = 0;
	mlx->data_y = 0;
	mlx->data_x1 = -2.1;
	mlx->data_y1 = -1.2;
	mlx->data_iteration_max = 50;
	mlx->data_image_x = SCREEN_X;
	mlx->data_image_y = SCREEN_Y;
	ft_browse_mandelbrot(mlx);
}

void	ft_mandelbrot(void)
{
	t_mlx	mlx;

	mlx.x = SCREEN_X;
	mlx.y = SCREEN_Y;
	mlx.mlx = mlx_init();
	if (mlx.mlx == NULL)
		return ;
	mlx.win = mlx_new_window(mlx.mlx, mlx.x, mlx.y, "Fractal - Mandelbrot");
	if (mlx.win == NULL)
		return ;
	ft_initialise(&mlx);
	mlx_key_hook(mlx.win, ft_esc_button, &mlx);
	mlx_hook(mlx.win, 17, 0L, ft_close_button, &mlx);
	mlx_hook(mlx.win, 4, 1L << 2, ft_zoom, &mlx);
	mlx_loop(mlx.mlx);
}
