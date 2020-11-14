/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/*
** The ft_striteri() function applies the function f to each character
** of the string passed as argument, and passing its index as first argument.
** Each character is passed by address to f to be modified if necessary.
**
** Функция ft_striteri() применяет функцию f к каждому символу
** передаваемой строки в качестве аргумента и передачи его индекса
** в качестве первого аргумента.
** Каждый символ передается по адресу f для изменения в случае необходимости.
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t i;

	i = 0;
	if (!s || !f)
		return ;
	while (*s)
	{
		(*f)(i, s);
		s++;
		i++;
	}
	return ;
}
