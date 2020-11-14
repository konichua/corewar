/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		parse_bit(t_format *spec, va_list vl)
{
	char		*str;
	uint64_t	unval;
	int			strlen;

	unval = va_arg(vl, uint64_t);
	str = NULL;
	strlen = 8;
	if (unval > 0xFF && unval <= 0xFFFF)
		strlen = 16;
	else if (unval > 0xFFFF)
		strlen = 32;
	if (spec->width - strlen > 0)
		spec->width = spec->width - strlen;
	else
		spec->width = 0;
	strlen = strlen + spec->width;
	str = record_bit(spec, str, strlen, unval);
	if (str)
	{
		write(spec->fd, str, strlen);
		free(str);
	}
	return (strlen);
}
