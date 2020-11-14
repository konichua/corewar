/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/*
** The memset() function fills the first n bytes of the memory area
** pointed to by s with the constant byte c.
**
** Функция заполняет первые n байтов той области памяти,
** на которую указывает s, постоянным байтом c.
*/

void			*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*temp;

	temp = (unsigned char*)b;
	i = 0;
	while (i < len)
	{
		temp[i] = c;
		i++;
	}
	return (b);
}
