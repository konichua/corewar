/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_sym_cmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		ft_str_sym_cmp(char *str_dad, char *str_son, char ch)
{
	int		i;

	i = 0;
	while (*str_dad && *str_son && *str_dad != ch)
	{
		if (*str_dad != *str_son)
			return (0);
		str_dad++;
		str_son++;
		i++;
	}
	return ((*str_dad == '}' && !*str_son) ? i : 0);
}
