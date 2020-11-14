/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/*
** The ft_strjoin() finction allocates (with malloc(3)) and returns a “fresh”
** string ending with ’\0’, result of the concatenation of s1 and s2.
** If the allocation fails the function returns NULL
**
** Функция ft_strjoin() распределяет (с помощью malloc (3))
** и возвращает «свежую» строку, заканчивающуюся на «0»,
** в результате объединения s1 и s2.
** Если распределение не выполнено, функция возвращает NULL
*/

char			*ft_strjoin(char const *s1, char const *s2)
{
	char		*dest;
	size_t		i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (NULL);
	while (*s1)
	{
		dest[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		dest[i] = *s2;
		i++;
		s2++;
	}
	dest[i] = '\0';
	return (dest);
}
