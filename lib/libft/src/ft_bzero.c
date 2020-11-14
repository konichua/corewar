/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/*
** The function  erases the data in the n bytes of the memory
** starting at the location pointed to by s, by writing zeros
** (bytes containing '\0') to that area.
**
** Функция устанавливает первые n байтов области,
** начинающейся с s в нули (пустые байты).
*/

void			ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	i = -1;
	temp = (unsigned char *)s;
	while (++i < n)
		temp[i] = '\0';
	return ;
}
