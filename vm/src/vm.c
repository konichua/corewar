/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		init_arena(uint8_t *arena, t_champion *champ[])
{
	uint8_t	i;
	uint8_t	count_champ;

	i = 0;
	count_champ = get_number_of_players();
	while (champ[i])
	{
		ft_memmove(&(arena[i * MEM_SIZE / count_champ]), champ[i]->code, \
					champ[i]->header.prog_size);
		i++;
	}
}

void		init_vm(t_vm *vm, t_champion *champ[], uint8_t *arena, \
					t_carriage *carriage)
{
	vm->champ = champ;
	vm->arena = arena;
	vm->carriage = carriage;
	vm->count_champs = get_number_of_players();
	vm->cycle_dump = get_number_dump_cycle();
	vm->cycle_to_die = CYCLE_TO_DIE;
	vm->iter_from_start = 0;
	vm->cycle_after_check = 0;
	vm->check_num = 0;
	vm->lives_num = 0;
	vm->carriage_num = vm->count_champs;
	vm->last_alive = NULL;
}
