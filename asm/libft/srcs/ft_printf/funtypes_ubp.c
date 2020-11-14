/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funtypes_ubp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_u(va_list ap)
{
	return (ft_itoabase(va_arg(ap, unsigned int), (unsigned int)10));
}

char	*ft_b(va_list ap)
{
	return (ft_itoabase(va_arg(ap, unsigned int), (unsigned int)2));
}

char	*ft_p(va_list ap)
{
	char *str;

	str = ft_itoahex((unsigned long long)va_arg(ap, void *), 'l');
	str = ft_stradd_front(str, ft_strlen(str) + 2, '0');
	str[1] = 'x';
	return (str);
}
