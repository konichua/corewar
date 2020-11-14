/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funtypes_sf_percent.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_percent(va_list ap)
{
	char *ans;

	if (!(ans = ft_strnew(2)) || ap == NULL)
		return (NULL);
	ans[0] = '%';
	ans[1] = '\0';
	return (ans);
}

char	*ft_s(va_list ap)
{
	char	*str;
	char	*buf;

	buf = va_arg(ap, char *);
	if (buf == NULL)
	{
		str = ft_strnew(6);
		str = ft_strcpy(str, "(null)\0");
	}
	else if (*buf == '\0')
		str = ft_strnew(1);
	else
	{
		str = ft_strnew(ft_strlen(buf));
		str = ft_strcpy(str, buf);
	}
	return (str);
}

char	*ft_f(va_list ap)
{
	long double number;
	char		*str;

	number = va_arg(ap, double);
	if (number != number)
	{
		str = ft_strnew(5);
		if (number > 0)
			return (ft_strcpy(str, "nan\0"));
		else
			return (ft_strcpy(str, "-nan\0"));
	}
	else if (number != 0 && number * 10 == number)
	{
		str = ft_strnew(5);
		if (number > 0)
			return (ft_strcpy(str, "inf\0"));
		else
			return (ft_strcpy(str, "-inf\0"));
	}
	return (ft_get_d(number));
}
