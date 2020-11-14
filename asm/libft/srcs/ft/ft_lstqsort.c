/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstqsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*help_lstsort(t_list *start, t_list *end,
		int (*comp)(t_list *, t_list *))
{
	t_list	*i;
	t_list	*j;
	t_list	*prev;
	int		flag;

	i = start;
	j = start;
	prev = start;
	flag = 0;
	while (j != end)
	{
		if ((*comp)(j, end) <= 0)
		{
			ft_lstswap(&prev, &i, &j);
			if (flag)
				prev = prev->next;
			i = i->next;
			flag = 1;
		}
		j = j->next;
	}
	ft_lstswap(&prev, &i, &j);
	return (prev);
}

void			ft_lstqsort(t_list **arr, t_list *first, t_list *last,
		int (*comp)(t_list *, t_list *))
{
	t_list *c;

	if (first->next)
		return ;
	c = help_lstsort(first, last, comp);
	ft_lstqsort(arr, first, c, comp);
	c = c->next;
	if (c->next)
		ft_lstqsort(arr, c->next, last, comp);
}
