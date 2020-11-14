/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/*
** The function copies n bytes from memory area src
** to memory area dest. The memory areas must not overlap.
**
** Функция копирует n байтов из области памяти src
** в область памяти dest. Области памяти не могут пересекаться.
*/

void			*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*dest_1;
	const unsigned char	*src_1;

	dest_1 = (unsigned char *)dest;
	src_1 = (unsigned char *)src;
	if (n != 0)
		while (n--)
		{
			*dest_1 = *src_1;
			if (*src_1 == (unsigned char)c)
				return (dest_1 + 1);
			dest_1++;
			src_1++;
		}
	return (NULL);
}
