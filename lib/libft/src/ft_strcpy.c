/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/*
** The strcpy() function copies the string pointed to by src,
** including the terminating null byte (aq\0aq), to the buffer
** pointed to by dest. The strings may not overlap,
** and the destination string dest must be large enough to receive the copy.
**
** Функция strcpy() копирует строку, на которую указывает src
** (включая завершающий символ `\0'), в массив, на который указывает dest.
** Строки не могут перекрываться, и в результирующей строке dest должно быть
** достаточно места для копии.
*/

char			*ft_strcpy(char *dest, const char *src)
{
	size_t		i;

	i = 0;
	while (i < ft_strlen(src))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
