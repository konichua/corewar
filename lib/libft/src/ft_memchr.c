/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/*
** The function scans the first n bytes of the memory area pointed
** to by s for the character c. The first byte to match c
** (interpreted as an unsigned character) stops the operation.
**
** Функция ищет символ c в первых n байтах той области памяти,
** на которую указывает s. Совпадение первого байта с c
** (представленным как беззнаковый символ) останавливает выполнение операции.
*/

void			*ft_memchr(const void *s, int c, size_t n)
{
	char		*dest;
	char		chr;

	chr = (char)c;
	dest = (char *)s;
	while (n--)
	{
		if (*dest == chr)
			return (dest);
		dest++;
	}
	return (NULL);
}
