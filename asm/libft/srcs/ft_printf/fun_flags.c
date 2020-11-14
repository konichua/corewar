/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*flags_minus(char *str, t_placeholder place)
{
	if (*str == '\0' && place.type.flag == 'c')
		return (str);
	return (ft_stradd_back(str, place.width, ' '));
}

char	*flags_plus(char *str, t_placeholder place)
{
	if (place.type.flag == '%' || place.type.flag == 'u' || *str == '-')
		return (str);
	if (place.sign == 0)
		return (ft_stradd_front(str, ft_strlen(str) + 1, '+'));
	else
		return (ft_stradd_front(str, ft_strlen(str) + 1, '-'));
}

char	*flags_space(char *str, t_placeholder place)
{
	if (place.type.flag == '%' || place.type.flag == 'u' || *str == '-')
		return (str);
	if (place.sign == 0)
		return (ft_stradd_front(str, ft_strlen(str) + 1, ' '));
	else
		return (ft_stradd_front(str, ft_strlen(str) + 1, '-'));
}

char	*flags_zero(char *str, t_placeholder place)
{
	if (place.type.flag == 'd' || place.type.flag == 'i'
			|| place.type.flag == 'o' || place.type.flag == '%'
			|| place.type.flag == 'u' || place.type.flag == 'x'
			|| place.type.flag == 'X' || place.type.flag == 'f')
	{
		if (place.width == 0)
			return (str);
		if (place.precision != -1 && place.type.flag != 'f')
			return (ft_stradd_front(str, place.precision, '0'));
		else if (place.sign == 0 && (place.flags & FLG_SPACE) == 0
								&& (place.flags & FLG_PLUS) == 0)
			return (ft_stradd_front(str, place.width, '0'));
		else
			return (ft_stradd_front(str, place.width - 1, '0'));
	}
	else
		return (str);
}
