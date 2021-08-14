/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 20:15:22 by vcavalca          #+#    #+#             */
/*   Updated: 2021/05/24 20:18:05 by vcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;
	int	ret;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	ret = ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (ret);
}
