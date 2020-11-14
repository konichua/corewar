/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		help_sort(int *arr, size_t *board,
		int (*comp)(const int *, const int *), void (*fswap)(void *, void *))
{
	size_t i;
	size_t j;

	i = board[0];
	j = board[0];
	while (j <= board[2])
	{
		if ((*comp)(&arr[j], &arr[board[2]]) <= 0)
		{
			fswap(&arr[i], &arr[j]);
			i++;
		}
		j++;
	}
	return (i - 1);
}

void			ft_qsort(int *arr, size_t *board,
		int (*comp)(const int *, const int *), void (*fswap)(void *, void *))
{
	int		c;
	size_t	tmp[2];

	if (board[0] >= board[1])
		return ;
	c = help_sort(arr, board, comp, fswap);
	if (c - 1 >= 0)
	{
		tmp[0] = board[0];
		tmp[1] = c - 1;
		ft_qsort(arr, &tmp[0], comp, fswap);
	}
	tmp[0] = c + 1;
	tmp[1] = board[2];
	ft_qsort(arr, &tmp[0], comp, fswap);
}
