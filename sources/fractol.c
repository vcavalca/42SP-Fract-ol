/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:31:40 by vcavalca          #+#    #+#             */
/*   Updated: 2021/09/02 20:14:05 by vcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_make_img(t_fractol *fractol)
{
	fractol->img = mlx_new_image(fractol->mlx, SCREEN_X, SCREEN_Y);
	if (fractol->img == NULL)
	{
		ft_putendl_fd(ERROR_INIT_IMG, 2);
		return (1);
	}
	fractol->addr = mlx_get_data_addr(fractol->img, &fractol->bits_per_pixel,
			&fractol->size_line, &fractol->endian);
	return (0);
}

int	ft_fractol_init(t_fractol *fractol)
{
	fractol->color = INIT_COLOR;
	fractol->side = INIT_X_POSITION;
	fractol->vert = INIT_Y_POSITION;
	fractol->mag = INIT_MAG;
	fractol->max_i = INIT_IMAX;
	fractol->mlx = mlx_init();
	if (fractol->mlx == NULL)
		return (1);
	fractol->mlx_win = mlx_new_window(fractol->mlx,
			SCREEN_X, SCREEN_Y, "Fractol");
	if (fractol->mlx_win == NULL)
		return (1);
	return (0);
}

int	ft_argv_check(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i] && s[i] != '.')
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	if (s[i])
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_args_verification(t_fractol *fractol, int argc, char **argv)
{
	if (argc == 2 && (!ft_strcmp_f(argv[1], "1") || !ft_strcmp_f(argv[1], "2")
			|| !ft_strcmp_f(argv[1], "4")))
		fractol->type = argv[1][0] - '0';
	else if (argc == 4 && !ft_strcmp_f(argv[1], "3") && ft_argv_check(argv[2])
		&& ft_argv_check(argv[3]))
	{
		fractol->type = argv[1][0] - '0';
		fractol->x_param = ft_atof(argv[2]);
		fractol->y_param = ft_atof(argv[3]);
	}
	else
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	ft_bzero(&fractol, 17);
	if (ft_args_verification(&fractol, argc, argv))
	{
		ft_error_print();
		return (1);
	}
	if (ft_fractol_init(&fractol) || ft_make_img(&fractol))
	{
		ft_free_mlx(&fractol);
		return (1);
	}
	ft_fractal(&fractol);
	mlx_mouse_hook(fractol.mlx_win, ft_mouse_click, &fractol);
	mlx_hook(fractol.mlx_win, 6, 1L << 6, ft_mouse_hook, &fractol);
	mlx_hook(fractol.mlx_win, 2, 1L << 0, ft_key_hook, &fractol);
	mlx_hook(fractol.mlx_win, BUTTON_CROSS, 1L << 17,
		ft_cross_button, &fractol);
	mlx_loop(fractol.mlx);
	return (0);
}
