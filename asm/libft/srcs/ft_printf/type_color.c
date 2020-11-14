/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "colors.h"

char	*ft_colour(va_list ap)
{
	char	*str;
	char	*buf;
	size_t	i;

	i = 0;
	buf = ft_strmap(va_arg(ap, char *), (char (*)(char))ft_tolower);
	str = ft_strnew(10);
	while (g_colors[i].color_name[0] != 'z')
	{
		if (ft_strcmp(g_colors[i].color_name, buf) == 0)
			str = ft_strcpy(str, g_colors[i].macros);
		i++;
	}
	if (buf)
		free(buf);
	return (str);
}
