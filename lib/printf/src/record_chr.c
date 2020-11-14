/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_chr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

char	*record_chr(t_format *spec, char *str, char ch)
{
	int	i;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * (spec->width))))
		return (NULL);
	i = spec->width - 1;
	str[i] = '\0';
	if (spec->minus == 1)
	{
		while (i > 0)
			str[i--] = ' ';
	}
	str[i--] = ch;
	if (spec->minus == 0)
	{
		while (i > 0)
			str[i--] = ' ';
		str[i] = ' ';
	}
	return (str);
}
