/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_count_size(t_data *data)
{
	int i;
	int size;
	int t_dir_size;

	size = 2;
	i = 0;
	t_dir_size = 4;
	if (g_op_tab[data->instrs[data->instr_num].id_instr].bit_type == 0)
		size--;
	if (g_op_tab[data->instrs[data->instr_num].id_instr].tdir_size == 1)
		t_dir_size = 2;
	while (i < g_op_tab[data->instrs[data->instr_num].id_instr].col_args)
	{
		if (data->instrs[data->instr_num].args[i].type == T_DIR)
			size += t_dir_size;
		else if (data->instrs[data->instr_num].args[i].type == T_IND)
			size += 2;
		else if (data->instrs[data->instr_num].args[i].type == T_REG)
			size++;
		i++;
	}
	data->instrs[data->instr_num].size = size;
}
