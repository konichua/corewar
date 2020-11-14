/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		op_st(t_vm *vm, t_carriage *carriage)
{
	t_arg		*args;
	int32_t		*regs;
	int32_t		address;
	int32_t		i;
	extern t_op	g_optab[17];

	args = carriage->args;
	regs = carriage->regs;
	if (args[SECOND].type == IND_CODE)
	{
		address = carriage->program_counter + args[SECOND].value % IDX_MOD;
		i = 0;
		while (i < 4)
		{
			*(vm->arena + address + i) = (regs[args[FIRST].value - 1] >> \
												((3 - i) * CHAR_BIT)) & 0xFF;
			i++;
		}
	}
	else if (args[SECOND].type == REG_CODE)
		regs[args[SECOND].value - 1] = regs[args[FIRST].value - 1];
}
