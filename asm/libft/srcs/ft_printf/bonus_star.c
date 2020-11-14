/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_star.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	star_precision(t_placeholder *placeholder, va_list ap)
{
	int p;

	if ((p = va_arg(ap, int)) < 0)
	{
		if (placeholder->width != 0)
			p = placeholder->width;
	}
	placeholder->precision = p;
	return (1);
}

int	star_width(t_placeholder *placeholder, const char *format, va_list ap)
{
	int w;

	if ((w = va_arg(ap, int)) < 0)
	{
		placeholder->flags |= FLG_MINUS;
		if (*(format + 1) == '.')
			placeholder->precision = w * (-1);
		else
			placeholder->width = w * (-1);
	}
	else
	{
		if (*(format + 1) == '.')
			placeholder->precision = w;
		else
			placeholder->width = w;
	}
	if (!ft_isdigit(*(format + 1)))
		return (1);
	return (0);
}
