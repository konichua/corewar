/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specifiers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

char	*parse_specifiers(t_format *spec, char *str, va_list vl)
{
	if (!*str)
		return (str);
	if (*str == '-' || *str == '+' || *str == ' ' || *str == '#' || *str == '0')
		str = is_flag(spec, str);
	if (*str == '*' || (*str >= '1' && *str <= '9'))
		str = is_width(spec, str, vl);
	if ((*str == '*' || (*str >= '1' && *str <= '9')) && spec->width == 0)
		str = is_width(spec, str, vl);
	if (*str == '.')
		str = is_accuracy(&spec->accur, ++str, vl);
	if (*str == 'l' || *str == 'L' || *str == 'h' || *str == 'z')
		str = is_size(&spec->size, str);
	if (*str > '$')
		str = is_type(&spec->type, str);
	return (str);
}
