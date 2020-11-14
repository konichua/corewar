/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/*
** The function writes the string s, without its terminating null byte ('\0'),
** ending by new line ('\n').
**
** Функция выводит строку s без завершающего символа ('\0'),
** заканчивающуюся переносом строки ('\n').
*/

void			ft_putendl(char const *s)
{
	ft_putstr(s);
	ft_putchar('\n');
	return ;
}
