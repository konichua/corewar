/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat_front(char *dest, const char *src,
		size_t len_buf, size_t len2)
{
	size_t		i;
	size_t		k;

	i = 0;
	k = 0;
	if (!dest || !src)
		return (NULL);
	while (k != len2)
	{
		k = len_buf - i;
		dest[k] = dest[len_buf - len2 - i];
		i++;
	}
	i = 0;
	while (i < len2)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
