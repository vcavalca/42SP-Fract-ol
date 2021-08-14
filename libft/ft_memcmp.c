/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 09:12:55 by vcavalca          #+#    #+#             */
/*   Updated: 2021/05/25 09:16:45 by vcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*new_s1;
	char	*new_s2;

	i = 0;
	new_s1 = (char *)s1;
	new_s2 = (char *)s2;
	while (n--)
	{
		if (new_s1[i] != new_s2[i])
			return ((unsigned char)new_s1[i] - (unsigned char)new_s2[i]);
		i++;
	}
	return (0);
}
