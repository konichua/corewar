/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static void	printf_printf(int fd, char *str, int *cnt)
{
	write(fd, str, 1);
	(*cnt)++;
	return ;
}

static int	print_b(t_format *spec, char *str, va_list vl, va_list fst_vl)
{
	int		cnt;

	cnt = 0;
	while (*str)
	{
		if (*str == '{')
			str = parse_bcolor(spec->fd, str);
		if (*str != '%')
			printf_printf(spec->fd, str, &cnt);
		else if (*str == '%')
		{
			str = parse_specifiers(spec, ++str, vl);
			if (spec->type)
				cnt = cnt + parse_output(spec, vl, fst_vl);
			else if (*str != '%' && *str)
				printf_printf(spec->fd, str, &cnt);
		}
		if (!*str)
			return (cnt);
		str++;
	}
	return (cnt);
}

int			ft_fprintf(int fd, const char *format, ...)
{
	char		*str;
	va_list		fst_vl;
	va_list		vl;
	int			cnt;
	t_format	spec[1];

	if (fd < 0 || fd > MAX_FD)
		return (-1);
	va_start(vl, format);
	va_copy(fst_vl, vl);
	init_spec_struct(spec, fd);
	str = (char *)format;
	cnt = print_b(spec, str, vl, fst_vl);
	va_end(vl);
	return (cnt);
}

int			ft_printf(const char *format, ...)
{
	char		*str;
	va_list		fst_vl;
	va_list		vl;
	int			cnt;
	t_format	spec[1];

	va_start(vl, format);
	va_copy(fst_vl, vl);
	init_spec_struct(spec, 1);
	str = (char *)format;
	cnt = print_b(spec, str, vl, fst_vl);
	va_end(vl);
	return (cnt);
}
