/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_digits(unsigned long long n, unsigned int base)
{
	int					count;
	unsigned long long	buf;

	count = 0;
	buf = n;
	if (n == 0)
		return (1);
	while (buf > 0)
	{
		buf /= base;
		count++;
	}
	return (count);
}

char			*ft_itoabase(unsigned long long n, unsigned int base)
{
	char	*str_n;
	int		count;
	size_t	i;

	count = ft_count_digits(n, base);
	str_n = ft_strnew(count);
	if (!str_n)
		return (NULL);
	i = count - 1;
	if (n == 0)
		str_n[i] = 0 + 48;
	while (n > 0)
	{
		str_n[i--] = n % base + 48;
		n /= base;
	}
	return (str_n);
}
