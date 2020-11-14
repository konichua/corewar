/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dipoxu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	parse_dipoxu_case(t_format *spec, uint64_t unval, int *num_len)
{
	if (spec->zero)
		if (spec->accur >= 0)
			spec->zero = 0;
	if (spec->accur >= 0)
		parse_dipoxu_accur(spec, unval, num_len);
	if (spec->sharp || spec->type == 'p')
		parse_dipoxu_sharp(spec, unval);
	if (spec->plus)
		parse_dipoxu_plus(spec);
	if (spec->space)
		parse_dipoxu_space(spec, *num_len);
	if (spec->width)
		parse_dipoxu_width(spec, *num_len);
	return ;
}

int		parse_dipoxu(t_format *spec, va_list vl)
{
	int			num_len;
	int64_t		ival;
	uint64_t	unval;

	ival = 0;
	unval = 0;
	if (spec->type == 'd' || spec->type == 'i')
	{
		ft_cast_size_di(spec, vl, &ival);
		if (ival < 0)
			(unval = ival * (-1));
		else
			(unval = ival);
	}
	else
		ft_cast_size_poxu(spec, vl, &unval);
	num_len = ft_numlen(unval, spec->base);
	parse_dipoxu_case(spec, unval, &num_len);
	return (parse_num(spec, unval, num_len));
}
