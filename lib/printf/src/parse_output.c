/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

/*
** while (i < BLYAT_SIZE)
** {
** if (spec->type == TYPES[i])
** {
** cnt = BLYAT[i](spec, vl);
** break ;
** }
** i++;
** }
** if (i == 5)
** cnt = BLYAT[i](spec, vl);
*/

int		parse_output(t_format *spec, va_list vl, va_list fst_vl)
{
	int			cnt;

	cnt = 0;
	if (spec->dollar > 1)
		parse_bdollar(spec->dollar, vl);
	if (spec->type == 'c')
		cnt = parse_chr(spec, vl);
	else if (spec->type == 's')
		cnt = parse_str(spec, vl);
	else if (spec->type == 'b')
		cnt = parse_bit(spec, vl);
	else if (spec->type == '%')
		cnt = parse_per(spec, vl);
	else if (spec->type == 'f' || spec->type == 'F')
		cnt = parse_float(spec, vl);
	else
		cnt = parse_dipoxu(spec, vl);
	if (spec->dollar == 0)
		va_copy(fst_vl, vl);
	else
		(va_copy(vl, fst_vl));
	return (cnt);
}
