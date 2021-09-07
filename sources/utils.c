/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 17:55:52 by vcavalca          #+#    #+#             */
/*   Updated: 2021/09/07 07:43:23 by vcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ft_esc_button(int key_code, t_mlx *mlx)
{
	if (key_code == 65307)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
		exit(0);
	}
	return (0);
}

int	ft_close_button(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	exit(0);
	return (0);
}

int	ft_julia_param(double cr, double ci, int if_param, t_mlx *mlx)
{
	if (if_param == 0)
	{
		mlx->c_r = 0.285;
		mlx->c_i = 0.01;
	}
	else if (if_param == 1)
	{
		mlx->c_r = cr;
		mlx->c_i = ci;
	}
	return (0);
}

double	ft_fmt_number(char *str, double res)
{
	int		i;
	int		j;
	double	tmp;

	i = 0;
	j = 1;
	if (*str == ',' || *str == '.')
	{
		++str;
		while (str[i] != '\0' && ft_isdigit(str[i]))
		{
			i++;
			j *= 10;
		}
		tmp = ft_atoi(str);
		res += (tmp / j);
	}
	return (res);
}

double	ft_fmt_param(char *str)
{
	double	res;
	int		sign;

	sign = 1;
	while ((*str < '0' || *str > '9') && *str != '-')
		str++;
	if (*str == '-')
	{
		++str;
		sign = -1;
	}
	res = ft_atoi(str);
	while (ft_isdigit(*str))
		++str;
	res = ft_fmt_number(str, res);
	return (res * sign);
}
