/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/*
** The ft_striter() applies the function f to each character
** of the string passed as argument.
** Each character is passed by address to f to be modified if necessary.
**
** Функция ft_striter() применяет функцию f к каждому символу
** передаваемой строки в качестве аргумента.
** Каждый символ передается по адресу f, чтобы изменить при необходимости.
*/

void			ft_striter(char *s, void (*f)(char *))
{
	if (!s || !f)
		return ;
	while (*s)
	{
		(*f)(s);
		s++;
	}
	return ;
}
