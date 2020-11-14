/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			op_sti(t_vm *vm, t_carriage *carriage)
{
	t_arg		*args;
	int32_t		*regs;
	int32_t		address;
	int			i;
	extern t_op	g_optab[17];

	args = carriage->args;
	regs = carriage->regs;
	take_args(vm->arena, carriage, FIRST);
	address = carriage->program_counter + (args[SECOND].value + \
												args[THIRD].value) % MEM_SIZE;
	address = address < 0 ? MEM_SIZE + address : address;
	i = 0;
	while (i < 4)
	{
		*(vm->arena + (address + i) % MEM_SIZE) = (regs[args[FIRST].value - 1] \
												>> ((3 - i) * CHAR_BIT)) & 0xFF;
		i++;
	}
}
