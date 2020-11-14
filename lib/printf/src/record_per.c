/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_per.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

char	*record_per(t_format *spec, int i)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * (i))))
		return (0);
	str[--i] = '\0';
	if (spec->minus == 1)
		while (i > 0)
			str[i--] = ' ';
	str[i--] = '%';
	if (spec->minus == 0)
	{
		while (i > 0)
		{
			if (spec->zero == 0)
				str[i--] = ' ';
			else if (spec->zero == 1)
				str[i--] = '0';
		}
		if (spec->zero == 0)
			str[i] = ' ';
		else if (spec->zero == 1)
			str[i] = '0';
	}
	return (str);
}
