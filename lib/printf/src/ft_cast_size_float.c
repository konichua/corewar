/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_size_float.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	ft_cast_size_float(t_format *spec, va_list vl, long double *fval)
{
	t_cast		sign_bit;

	if (spec->size == 5)
		*fval = va_arg(vl, long double);
	else
		*fval = (long double)va_arg(vl, double);
	if (*fval == LDBL_MIN || *fval == -LDBL_MIN)
	{
		if (*fval == -LDBL_MIN)
			spec->sign = 1;
		*fval = (long double)0.0;
	}
	if (*fval <= 0)
	{
		sign_bit = (t_cast){ .ld = *fval };
		if (sign_bit.t_parts.sign & 1)
			spec->sign = 1;
		*fval = *fval * (-1);
	}
	return ;
}
