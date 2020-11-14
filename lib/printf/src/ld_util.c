/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

char	*ft_make_full_str(char *full_str, int pres, char sharp)
{
	char	just_dot[2];

	just_dot[0] = '.';
	just_dot[1] = '\0';
	full_str = make_rounding(&full_str, pres);
	if (full_str[ft_strlen(full_str) - 1] == '.')
		full_str[ft_strlen(full_str) - 1] = '\0';
	if (pres == 0 && sharp)
		full_str = ft_strjoin(full_str, just_dot);
	return (full_str);
}

char	*ft_make_new_str(char *new_str, char *str)
{
	char one[2];

	one[0] = '1';
	one[1] = '\0';
	new_str = ft_strjoin(one, str);
	ft_strdel(&str);
	return (new_str);
}
