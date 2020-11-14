/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/*
** The strdup() function returns a pointer to a new string which is a duplicate
** of the string s. Memory for the new string is obtained with malloc(3),
** and can be freed with free(3).
**
** Функция strdup() возвращает указатель на новую строку,
** являющуюся дубликатом строки s.
** Память под новую строку выделятся с помощью malloc(3)
** и может быть высвобождены с помощью free(3).
*/

char			*ft_strdup(const char *s)
{
	size_t		i;
	size_t		strlen;
	char		*tmp;

	i = 0;
	strlen = ft_strlen(s);
	tmp = NULL;
	tmp = (char *)malloc(sizeof(char) * (strlen + 1));
	if (tmp == NULL)
		return (NULL);
	while (i < strlen)
	{
		tmp[i] = s[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
