/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*buf;
	t_list	*head;

	if (!lst || !f)
		return (NULL);
	buf = (t_list *)malloc(sizeof(t_list));
	if (!buf)
		return (NULL);
	buf = (*f)(lst);
	head = buf;
	while (lst->next)
	{
		lst = lst->next;
		ft_lstadd_back(&buf, (*f)(lst));
		if (!buf)
			return (NULL);
		buf = buf->next;
	}
	return (head);
}
