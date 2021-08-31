/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcavalca <vcavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:20:39 by vcavalca          #+#    #+#             */
/*   Updated: 2021/05/26 14:08:47 by vcavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*back;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst)
	{
		back = ft_lstlast(*lst);
		back->next = &*new;
	}
	else
		*lst = new;
}
