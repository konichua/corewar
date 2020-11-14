/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove_if.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstremove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*previous;
	t_list	*next;

	previous = *begin_list;
	next = *begin_list;
	while (next && (*cmp)(next->content, data_ref) == 0)
	{
		*begin_list = next->next;
		free(next);
		next = *begin_list;
	}
	while (next)
	{
		previous = *begin_list;
		while (next && (*cmp)(next->content, data_ref) != 0)
			next = next->next;
		while (next && previous->next != next)
			previous = previous->next;
		if (next)
		{
			previous->next = next->next;
			free(next);
			next = previous->next;
		}
	}
}
