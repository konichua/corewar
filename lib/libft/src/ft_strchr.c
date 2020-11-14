/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/*
** The strchr() function returns a pointer to the first occurrence
** of the character c in the string s.
**
** Функция strchr() возвращает указатель на местонахождение
** первого совпадения с символом c в строке s.
*/

char			*ft_strchr(const char *s, int c)
{
	char		chr;
	size_t		i;
	size_t		n;

	i = ft_strlen(s);
	n = 0;
	chr = c;
	while (n <= i)
	{
		if (s[n] == chr)
			return ((char *)s + n);
		n++;
	}
	return (NULL);
}
