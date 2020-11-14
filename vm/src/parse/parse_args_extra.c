/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args_extra.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	возвращает начальное количество игроков
*/

uint8_t		get_number_of_players(void)
{
	uint8_t	i;
	int8_t	n;

	i = 0;
	n = update_n_flag(-1);
	while (n)
	{
		n = n & (n - 1);
		i++;
	}
	return (i);
}

/*
**	возвращает номер цикла, на котором дампим память
*/

int32_t		get_number_dump_cycle(void)
{
	return (update_dump_flag(-1));
}

int32_t		update_dump_flag(const int32_t dump_flag)
{
	static int32_t	dump = -1;

	if (dump_flag > -1)
		dump = dump_flag;
	return (dump);
}

int8_t		update_n_flag(const int8_t shift)
{
	static int8_t	n_positions = 0;

	if (n_positions & 1 << shift)
		return (-1);
	n_positions = n_positions | 1 << shift;
	return (n_positions);
}

uint8_t		update_limit_number(uint8_t i)
{
	static uint8_t	limit = 0;

	if (i)
		limit++;
	return (limit);
}
