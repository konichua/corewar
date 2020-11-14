/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_size_poxu.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	ft_cast_size_poxu(t_format *spec, va_list ap, u_int64_t *ival)
{
	if (spec->size == 1)
		*ival = (unsigned short)va_arg(ap, int);
	else if (spec->size == 2)
		*ival = (unsigned char)va_arg(ap, int);
	else if (spec->size == 3)
		*ival = va_arg(ap, unsigned long);
	else if (spec->size == 4)
		*ival = va_arg(ap, unsigned long long);
	else if (spec->type == 'p')
		*ival = va_arg(ap, unsigned long long);
	else
		*ival = va_arg(ap, unsigned int);
	if (spec->type == 'u')
		spec->base = 10;
	else if (spec->type == 'o')
		spec->base = 8;
	else
		spec->base = 16;
	return ;
}
