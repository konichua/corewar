/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/*
** The function takes as a parameter the address of a memory area that needs
** to be freed with free(), then puts the pointer to NULL.
**
** Функция принимает в качестве параметра адрес области памяти, которая должна
** быть освобождена с помощью free(), указателю присваевается NULL.
*/

void			ft_memdel(void **ap)
{
	if (!ap)
		return ;
	else if (!*ap)
		return ;
	else
	{
		free(*ap);
		*ap = NULL;
	}
	return ;
}
