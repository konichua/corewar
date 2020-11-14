/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_chr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		parse_chr(t_format *spec, va_list vl)
{
	char			ch;
	char			*str;

	str = NULL;
	ch = (char)va_arg(vl, int);
	if (spec->width > 1)
	{
		str = record_chr(spec, str, ch);
		if (str)
		{
			write(spec->fd, str, spec->width);
			free(str);
		}
	}
	else
	{
		write(spec->fd, &ch, 1);
		return (1);
	}
	return (spec->width);
}
