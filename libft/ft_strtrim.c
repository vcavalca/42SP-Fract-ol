/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 11:42:43 by vcavalca          #+#    #+#             */
/*   Updated: 2021/06/09 14:11:37 by vcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_char_in_set(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_s1;
	size_t	start;
	size_t	end;
	size_t	i;

	i = 0;
	start = 0;
	if (set == NULL)
		return ((char *)s1);
	if (s1 == NULL)
		return (NULL);
	while (s1[start] && ft_find_char_in_set(set, s1[start]) == 1)
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_find_char_in_set(set, s1[end - 1]) == 1)
		end--;
	new_s1 = (char *)ft_strmalloc((end - start));
	if (new_s1 == NULL)
		return (NULL);
	while (start < end)
		new_s1[i++] = s1[start++];
	new_s1[i] = '\0';
	return (new_s1);
}
