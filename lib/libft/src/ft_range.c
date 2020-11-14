/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int		*ft_range(int min, int max)
{
	int i;
	int z;
	int n;
	int *array;

	n = 0;
	i = max - min;
	if (i <= 0)
		return (0);
	array = (int *)malloc(sizeof(int) * i);
	if (array == NULL)
		return (0);
	z = min;
	while (z < max)
	{
		array[n] = z;
		z++;
		n++;
	}
	return (array);
}
