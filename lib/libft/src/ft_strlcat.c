/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/*
** The strlcat () function appends the NUL-terminated string src
** to the end of dest.
** It will append at most size - strlen(dest) - 1 bytes,
** NUL-terminating the result.
*/

size_t			ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		i;
	size_t		n;

	i = ft_strlen(dest);
	n = ft_strlen(src);
	if (i > size)
		i = size;
	if (i == size)
		return (size + n);
	if (n < size - i)
		ft_memcpy(dest + i, src, n + 1);
	else
	{
		ft_memcpy(dest + i, src, size - i - 1);
		dest[size - 1] = '\0';
	}
	return (i + n);
}
