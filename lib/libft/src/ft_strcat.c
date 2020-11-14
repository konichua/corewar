/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/*
** The strcat() function appends the src string to the dest string,
** overwriting the null byte (aq\0aq) at the end of dest,
** and then adds a terminating null byte.
** The strings may not overlap, and the dest string must have
** enough space for the result.
**
** Функция strcat() добавляет строку str к строке dest,
** перезаписывая символ `\0' в конце dest и добавляя к строке
** символ окончания `\0'.
** Строки не могут перекрываться, а в строке dest должно хватать
** свободного места для размещения объединенных строк.
*/

char			*ft_strcat(char *dest, const char *src)
{
	size_t		i;
	size_t		z;

	z = 0;
	i = ft_strlen(dest);
	while (src[z] != '\0')
	{
		dest[i] = src[z];
		z++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
