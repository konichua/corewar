/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		reset_lives_num(t_vm *vm)
{
	int32_t		i;

	i = 0;
	while (i < vm->count_champs)
	{
		vm->champ[i]->prev_lives_num = vm->champ[i]->curr_lives_num;
		vm->champ[i]->curr_lives_num = 0;
		i++;
	}
	vm->lives_num = 0;
}

static int8_t	is_died(t_vm *vm, t_carriage *carriage)
{
	return (vm->cycle_to_die <= 0
			|| vm->iter_from_start - carriage->last_live >= vm->cycle_to_die);
}

static void		delete_died_carriage(t_vm *vm)
{
	t_carriage	*prev;
	t_carriage	*curr;
	t_carriage	*del;

	prev = NULL;
	curr = vm->carriage;
	while (curr)
	{
		if (is_died(vm, (del = curr)) && --vm->carriage_num)
		{
			curr = curr->next;
			if (vm->carriage == del)
				vm->carriage = curr;
			if (prev)
				prev->next = curr;
			ft_memdel((void **)&del->args);
			ft_memdel((void **)&del);
		}
		else
		{
			prev = curr;
			curr = curr->next;
		}
	}
}

void			cycles_to_die_check(t_vm *vm)
{
	vm->check_num++;
	delete_died_carriage(vm);
	if (vm->check_num == MAX_CHECKS || vm->lives_num >= NBR_LIVE)
	{
		vm->cycle_to_die -= CYCLE_TO_DIE;
		vm->check_num = 0;
	}
	reset_lives_num(vm);
	vm->cycle_after_check = 0;
}
