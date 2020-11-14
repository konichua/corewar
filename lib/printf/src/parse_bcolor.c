/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bcolor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

/*
** norminette - кусок говна
** char	*parse_bcolor(char *str)
** {
**	int	i;
**
**	i = 0;
**	str++;
**	while (i < COLOR_SIZE)
**	{
**		if (*str == COLOR[i][0])
**		{
**			if (ft_str_sym_cmp(str, (char *)COLOR[i], '}'))
**			{
**				write(spec->fd, OUT_COLOR[i], OUT_COLOR_POINT[i]);
**				i = COLOR_POINT[i];
**				return (str + i);
**			}
**			else
**				break ;
**		}
**		i++;
**	}
**	return (--str);
** }
*/

char	*parse_bcolor(int fd, char *str)
{
	int		i;

	i = 0;
	str++;
	if ((*str == 'r') && ((i = ft_str_sym_cmp(str, "red", '}')) > 0))
		write(fd, "\e[38;5;196m", 11);
	else if ((*str == 'g') && ((i = ft_str_sym_cmp(str, "green", '}')) > 0))
		write(fd, "\e[38;5;48m", 10);
	else if ((*str == 'b') && ((i = ft_str_sym_cmp(str, "blue", '}')) > 0))
		write(fd, "\e[38;5;69m", 10);
	else if ((*str == 'y') && ((i = ft_str_sym_cmp(str, "yellow", '}')) > 0))
		write(fd, "\e[38;5;226m", 11);
	else if ((*str == 'o') && ((i = ft_str_sym_cmp(str, "orange", '}')) > 0))
		write(fd, "\e[38;5;208m", 11);
	else if ((*str == 'p') && ((i = ft_str_sym_cmp(str, "pink", '}')) > 0))
		write(fd, "\e[38;5;205m", 11);
	else if ((*str == 'n') && ((i = ft_str_sym_cmp(str, "neon", '}')) > 0))
		write(fd, "\e[38;5;123m", 11);
	else if ((*str == 'e') && ((i = ft_str_sym_cmp(str, "eoc", '}')) > 0))
		write(fd, "\e[0m", 4);
	return ((i > 0) ? (str + i + 1) : (--str));
}
