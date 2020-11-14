/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/*
** The ft_strclr() sets every character of the string to the value ’\0’.
**
** Функция ft_strclr() устанавливает для каждого символа строки значение ’\ 0’.
*/

void			ft_strclr(char *s)
{
	if (s != 0)
		ft_bzero(s, ft_strlen(s));
	return ;
}
