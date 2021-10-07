/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:31:40 by vcavalca          #+#    #+#             */
/*   Updated: 2021/09/21 06:43:53 by vcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	ft_parameters(int argc, char **argv)
{
	int	compare;
	int	i;

	i = 0;
	if (argc > 1)
	{
		while (argv[1][i] != '\0')
		{
			argv[1][i] = ft_tolower(argv[1][i]);
			i++;
		}
	}
	if (argc >= 4)
	{
		compare = ft_strncmp(argv[1], "julia", 6);
		if (compare == 0)
			return (2);
	}
	return (-1);
}

static void	ft_error_message(int error)
{
	if (error != 0 && error != 1 && error != 2)
	{
		printf("To use ./fractol + parameters bellow :\n");
		printf("* Mandelbrot\n");
		printf("* Julia\n");
		printf("* To draw your own julia set,");
		printf(" use the parameter with two option\n");
		printf("*Ex: Julia -0.943256 0.239852");
		printf("\n");
	}
}

int	main(int argc, char **argv)
{
	int	error;
	int	compare;

	error = ft_parameters(argc, argv);
	if (error == 2)
		ft_julia(ft_fmt_param(argv[2]), ft_fmt_param(argv[3]), 1);
	else if (argc >= 2)
	{
		compare = ft_strncmp(argv[1], "julia", 6);
		if (compare == 0)
			error = 0;
		compare = ft_strncmp(argv[1], "mandelbrot", 11);
		if (compare == 0)
			error = 1;
	}
	if (error == 1)
		ft_mandelbrot();
	if (error == 0)
		ft_julia(0, 0, 0);
	ft_error_message(error);
	return (0);
}
