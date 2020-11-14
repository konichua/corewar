/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strnstr(const char *dest, const char *src, size_t len)
{
	size_t i;
	size_t s2_len;

	if (!*src)
		return ((char *)dest);
	s2_len = ft_strlen(src);
	while (*dest && len >= s2_len)
	{
		i = 0;
		while (*(src + i) && *(dest + i) == *(src + i))
			i++;
		if (*(src + i) == '\0')
			return ((char *)dest);
		dest++;
		len--;
	}
	return (NULL);
}
