/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_unixtime.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*ft_joinmalloc(char *s1, char *s2)
{
	char *ans;

	ans = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (ans);
}

static char		*ft_joinmalloc1(char *s1, const char *s2)
{
	char *ans;

	ans = ft_strjoin(s1, s2);
	free(s1);
	return (ans);
}

char			*ft_unix_to_isodate(va_list ap)
{
	t_utime	ut;
	char	*strdate;

	ut = unix_to_struct(va_arg(ap, int));
	if (ut.month < 10)
		strdate = ft_joinmalloc1(ft_itoa(ut.year), "-0");
	else
		strdate = ft_joinmalloc1(ft_itoa(ut.year), "-");
	strdate = ft_joinmalloc(strdate, ft_itoa(ut.month));
	if (ut.day > 10)
		strdate = ft_joinmalloc1(strdate, "-");
	else
		strdate = ft_joinmalloc1(strdate, "-0");
	strdate = ft_joinmalloc(strdate, ft_itoa(ut.day));
	return (strdate);
}
