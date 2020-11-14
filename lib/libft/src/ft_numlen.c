/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/*
** The function takes an unsigned number, and the number system
** and returns its length, necessary for writing this number to a string
**
** Функция принимает беззнаковое число, а также систему счисления
** и возвращает его длину, нужную для записи этого числа в строку
*/

int				ft_numlen(long long value, int base)
{
	int			i;
	int			neg;

	if (base < 2 || base > 16 || base % 2 != 0)
		return (0);
	i = 0;
	neg = 0;
	if (value == 0)
		return (1);
	if (value < 0)
		neg = 1;
	while (value)
	{
		value /= base;
		i++;
	}
	return (i + neg);
}
