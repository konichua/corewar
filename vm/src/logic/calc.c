/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

uint32_t	step_size(uint8_t arg_type, t_op op)
{
	if (arg_type & T_REG)
		return (1);
	else if (arg_type & T_DIR)
		return (op.tdir_size);
	else if (arg_type & T_IND)
		return (IND_SIZE);
	return (0);
}

uint32_t	calc_step(t_carriage *carriage)
{
	int32_t		i;
	uint32_t	step;
	extern t_op	g_optab[17];

	i = 0;
	step = 0;
	step += OPCODE_SIZE + (g_optab[carriage->opcode - 1].bit_type ? 1 : 0);
	while (i < g_optab[carriage->opcode - 1].col_args)
	{
		step += step_size(carriage->args[i].type, g_optab[carriage->opcode \
																		- 1]);
		i++;
	}
	return (step);
}

int32_t		calc_addr(int32_t addr)
{
	addr %= MEM_SIZE;
	if (addr < 0)
		addr += MEM_SIZE;
	return (addr);
}
