/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabasex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	ft_itoabasex(t_format *spec, uint64_t i, char *s, int num_len)
{
	uint64_t nymsys;

	nymsys = spec->base;
	while (i > 0)
	{
		if (i < nymsys)
		{
			if (spec->type != 'X')
				(s[num_len] = IT[i]);
			else
				(s[num_len] = ITX[i]);
			return ;
		}
		else
		{
			if (spec->type != 'X')
				(s[num_len] = IT[i % nymsys]);
			else
				(s[num_len] = ITX[i % nymsys]);
		}
		i = i / nymsys;
		num_len--;
	}
	return ;
}
