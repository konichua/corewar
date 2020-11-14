/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char			*ft_itoa_base(int val, int base)
{
	int				neg;
	int				len;
	unsigned int	unv;
	char			*tmp;

	if (base < 2 || base > 16 || base % 2 != 0)
		return (NULL);
	unv = 0;
	neg = (val < 0 && base == 10) ? 1 : 0;
	unv = (val < 0) ? val * -1 : val;
	len = neg + ft_numlen(unv, base);
	if (!(tmp = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	tmp[len] = '\0';
	while (--len >= 0)
	{
		tmp[len] = (unv % base < 10) ? unv % base + '0' : unv % base + 'A' - 10;
		unv /= base;
	}
	if (neg)
		tmp[0] = '-';
	return (tmp);
}
