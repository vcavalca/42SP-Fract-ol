/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:40:49 by vcavalca          #+#    #+#             */
/*   Updated: 2021/05/27 16:08:25 by vcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_char_position_counter(int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
	{
		i++;
		n = (-1) * n;
	}
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*s;
	size_t	i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = ft_char_position_counter(n);
	s = ft_strmalloc(i);
	if (s == NULL)
		return (NULL);
	s[i] = '\0';
	if (n < 0)
	{
		n *= -1;
		s[0] = '-';
	}
	while (n > 9)
	{
		s[i - 1] = n % 10 + '0';
		n /= 10;
		i--;
	}
	s[i - 1] = n + '0';
	return (s);
}
