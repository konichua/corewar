/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/*
** The function checks for a number in a string
** out of range (-2147483648 to 2147483647)
** (may contain one sign at the start and digits).
**
** Функция проверяет, является ли строка числом,
** входящим в диапозон (-2147483648 до 2147483647)
** (может содержать один знак вначале и цифры).
*/

int				ft_isnumber_int(const char *str)
{
	int			len;

	len = 0;
	if (!str)
		return (0);
	len = ft_strlen(str);
	if (len > 11 || len == 0 || (ft_isnumber(str) == 0))
		return (0);
	if (len == 10)
	{
		if (*str == '-' || *str == '+')
			return (1);
		else if (ft_strcmp(SINT_MAX, str) < 0)
			return (0);
	}
	if (len == 11)
	{
		if (*str != '-' && *str != '+')
			return (0);
		if (*str == '-')
			return ((ft_strcmp(SINT_MIN, str) < 0) ? 0 : 1);
		if (*str == '+')
			return ((ft_strcmp(SINT_MAX_P, str) < 0) ? 0 : 1);
	}
	return (1);
}
