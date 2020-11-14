/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			exit_error(const char *str)
{
	ft_fprintf(STDERR_FILENO, "%s%s\n", E_ERR, str);
	exit(EXIT_FAILURE);
}

static void		initialization(char *champ_names[], t_champion *champ[], \
								uint8_t *arena, t_carriage **carriage)
{
	init_arrptr((void *)champ_names, MAX_PLAYERS + 1);
	init_arrptr((void *)champ, MAX_PLAYERS + 1);
	ft_memset(arena, 0, MEM_SIZE);
	*carriage = NULL;
}

int				main(int argc, char **argv)
{
	char		*champ_names[MAX_PLAYERS + 1];
	t_champion	*champ[MAX_PLAYERS + 1];
	uint8_t		arena[MEM_SIZE];
	t_carriage	*carriage;
	t_vm		vm[1];

	if (argc < MIN_ARGS_NUMBER + 1)
		exit_error(E_USAGE);
	argv++;
	initialization(champ_names, champ, arena, &carriage);
	parse_args(champ_names, argv);
	parse_files(champ, champ_names);
	init_arena(arena, champ);
	set_starter_kit_carriage(&carriage, arena);
	init_vm(vm, champ, arena, carriage);
	game(vm);
	free_arrptr((void *)champ_names);
	free_champ(champ);
	free_carriage_list(&(vm->carriage));
	return (0);
}
