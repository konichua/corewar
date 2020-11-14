/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		op_lld(t_vm *vm, t_carriage *carriage)
{
	t_arg		*args;
	int32_t		i;
	int32_t		address;
	extern t_op	g_optab[17];

	i = 0;
	args = carriage->args;
	while (i < g_optab[carriage->opcode - 1].col_args)
	{
		if (args[i].type == IND_CODE)
		{
			address = carriage->program_counter + args[i].value % MEM_SIZE;
			args[i].value = *(vm->arena + address + (address > 0 ? 0 : \
																	MEM_SIZE));
		}
		i++;
	}
	carriage->regs[args[SECOND].value - 1] = args[FIRST].value;
	carriage->carry = carriage->regs[args[SECOND].value - 1] == 0 ? 1 : 0;
}
