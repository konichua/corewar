/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/*
** The function copies n bytes
** from memory area src to memory area dest.
** The memory areas should not overlap.
** Use memmove() if the memory areas do overlap.
**
** Функция копирует n байтов из области памяти src
** в область памяти dest. Области памяти не могут пересекаться.
** Используйте memmove(), если области памяти перекрываются.
*/

void			*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_1;
	const unsigned char	*src_1;

	dest_1 = (unsigned char *)dest;
	src_1 = (unsigned char *)src;
	if (dest_1 == NULL && src_1 == NULL)
		return (NULL);
	while (n--)
	{
		*dest_1 = *src_1;
		dest_1++;
		src_1++;
	}
	return (dest);
}
