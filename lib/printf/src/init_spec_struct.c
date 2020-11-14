/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_spec_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	init_spec_struct(t_format *spec, int fd)
{
	spec->fd = fd;
	spec->width = 0;
	spec->accur = -1;
	spec->dollar = 0;
	spec->sign = 0;
	spec->base = 0;
	spec->minus = 0;
	spec->plus = 0;
	spec->space = 0;
	spec->sharp = 0;
	spec->zero = 0;
	spec->size = 0;
	spec->type = 0;
	return ;
}
