/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:02:10 by vcavalca          #+#    #+#             */
/*   Updated: 2021/05/26 12:42:34 by vcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_counter(char const *s, char c)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			counter++;
		while (s[i] != '\0' && (s[i] != c))
			i++;
	}
	return (counter);
}

static char	*ft_malloc_strncpy(const char *s, size_t n)
{
	char	*new_s;

	new_s = (char *)ft_strmalloc(n);
	if (new_s == NULL)
		return (NULL);
	new_s = ft_strncpy(new_s, s, n);
	new_s[n] = '\0';
	return (new_s);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**new_s;

	i = 0;
	k = 0;
	new_s = (char **)ft_strmalloc(sizeof(char *) * ft_word_counter(s, c));
	if (new_s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
		{
			new_s[k] = ft_malloc_strncpy(s + j, i - j);
			k++;
		}
	}
	new_s[k] = NULL;
	return (new_s);
}
