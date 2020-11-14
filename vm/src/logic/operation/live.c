/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		op_live(t_vm *vm, t_carriage *carriage)
{
	t_arg		*args;
	int32_t		player_id;
	t_champion	*champ;
	extern t_op	g_optab[17];

	args = carriage->args;
	vm->lives_num++;
	carriage->last_live = vm->iter_from_start;
	player_id = args[FIRST].value;
	if (player_id <= -1 && player_id >= -vm->count_champs)
	{
		champ = vm->champ[(-player_id) - 1];
		champ->last_live = vm->iter_from_start;
		champ->curr_lives_num++;
		vm->last_alive = champ;
	}
}
