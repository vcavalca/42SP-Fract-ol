/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 09:30:34 by vcavalca          #+#    #+#             */
/*   Updated: 2021/05/25 09:34:08 by vcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	find;
	char	*new_s;

	find = (char)c;
	new_s = (char *)s;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (new_s[i] == find)
			return (new_s + i);
		i--;
	}
	if (new_s[i] == find)
		return (new_s);
	return (NULL);
}
