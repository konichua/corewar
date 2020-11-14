/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_size_di.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	ft_cast_size_di(t_format *spec, va_list ap, int64_t *ival)
{
	if (spec->size == 0)
		*ival = va_arg(ap, int);
	else if (spec->size == 1)
		*ival = (short)va_arg(ap, int);
	else if (spec->size == 2)
		*ival = (char)va_arg(ap, int);
	else if (spec->size == 3)
		*ival = va_arg(ap, long);
	else if (spec->size == 4)
		*ival = va_arg(ap, long long);
	spec->base = 10;
	if (*ival < 0)
		spec->sign = 1;
	return ;
}
