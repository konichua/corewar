/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/*
** The function prints given number of type int.
**
** Функция выводит данное число типа int.
*/

void			ft_putnbr(int n)
{
	if (n >= 0 && n <= 9)
		return (ft_putchar(n + '0'));
	else if (n == INT_MIN)
	{
		ft_putstr("-2");
		ft_putnbr(0x8CA6C00);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(n * -1);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + 48);
	}
	return ;
}
