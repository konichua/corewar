/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/*
** The function checks whether c is a 7-bit unsigned char value
** that fits into the ASCII character set.
**
** Функция проверяет, является ли c 7-битным unsigned char,
** значение которого попадает в таблицу символов ASCII.
*/

int				ft_isascii(int c)
{
	return (c >= 0 && c <= 127 ? 1 : 0);
}
