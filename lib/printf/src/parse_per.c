/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_per.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		parse_per(t_format *spec, va_list vl)
{
	int		str_len;
	char	*str;

	if (!vl)
		return (0);
	str = NULL;
	str_len = spec->width;
	if (str_len > 1)
		str = record_per(spec, str_len);
	else
	{
		write(spec->fd, "%", 1);
		return (1);
	}
	write(spec->fd, str, str_len);
	free(str);
	return (str_len);
}
