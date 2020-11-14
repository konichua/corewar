/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/*
** Takes as a parameter the address of a string that need to be
** freed with free(), then sets its pointer to NULL.
**
** Функция ft_strdel() принимает в качестве параметра адрес строки,
** которая должна быть освобождена с помощью free (3),
** затем устанавливает указатель на NULL.
*/

void			ft_strdel(char **str)
{
	if (!str)
		return ;
	else if (!*str)
		return ;
	else
	{
		free(*str);
		*str = NULL;
	}
	return ;
}
