/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char		*ft_strnew_size(char **str, int size)
{
	int		strlen;
	char	*tmp;

	strlen = ft_strlen(*str);
	tmp = NULL;
	if (strlen >= size || strlen == 0)
		return (*str);
	if (!(tmp = (char *)malloc(sizeof(char) * (size + 1))))
		return (*str);
	tmp[size--] = '\0';
	while (--strlen >= 0)
	{
		tmp[size] = (*str)[strlen];
		size--;
	}
	while (size >= 0)
	{
		tmp[size] = ' ';
		size--;
	}
	ft_strdel(&(*str));
	return (tmp);
}
