/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 10:25:32 by vcavalca          #+#    #+#             */
/*   Updated: 2021/05/26 12:30:26 by vcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmalloc(size_t size)
{
	char	*c;

	c = (char *)malloc(size + 1);
	if (c == NULL)
		return (NULL);
	return (c);
}
