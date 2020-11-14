/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**  СПАСИБО НОРМЕ ЗА ЭТО, ХУЛИ. ПРИЯТНЫЙ КОД-СТИЛЬ
*/

static void		check_missed_pos_order(void)
{
	uint8_t		i;
	int8_t		n;

	i = MAX_PLAYERS - 1;
	n = update_n_flag(-1);
	if (!n)
		exit_error(E_ARGV_NO_PLAYERS);
	while (i)
	{
		if ((n & 1 << i) && !(n & 1 << (i - 1)))
			exit_error(E_ARGV_BAD_ORDER);
		i--;
	}
}

static void		merge_champ_names(char **champ_names, \
									char **unranking_champ_names)
{
	uint8_t	i;
	uint8_t	n;

	i = 0;
	n = 0;
	while (i < MAX_PLAYERS)
	{
		if (!champ_names[i])
		{
			while (n < MAX_PLAYERS)
			{
				if (unranking_champ_names[n])
				{
					champ_names[i] = unranking_champ_names[n];
					update_n_flag(i);
					n++;
					break ;
				}
				n++;
			}
		}
		i++;
	}
}

static size_t	parse_set_splited_argv(char ***splited_argv, char **argv)
{
	size_t	i;

	i = 0;
	if (argv[1])
		*splited_argv = argv;
	else
	{
		*splited_argv = ft_strsplit(argv[0], ' ');
		if (!*splited_argv || !*splited_argv[0])
			exit_error(E_SSPLIT);
	}
	if (parse_dump_flag(*splited_argv))
		i = 2;
	return (i);
}

static void		parse_init(char *unranking_champ_names[], uint8_t *n)
{
	init_arrptr((void *)unranking_champ_names, MAX_PLAYERS + 1);
	*n = 0;
}

/*
**	аргументы могут придти двумя способами:
**	./corewar -dump nbr_cycles -n number champion1.cor
**	./corewar "-dump nbr_cycles -n number champion1.cor"
**	прочие скобочные хуйни идут нахуй, например
**	./corewar "-dump n" "-n number" "champion1.cor" идет нахуй
**
**	проверяем каким способом пришли аргументы
**	проверяем флаг -dump (если существует, должен находиться первым аргументом)
**	проверяем флаг -n
**	проверяем игрока (должно быть 'расширение' .cor)
*/

void			parse_args(char *champ_names[], char **argv)
{
	char		*unrnkng_champ_names[MAX_PLAYERS + 1];
	char		**splited_argv;
	size_t		i;
	uint8_t		n;
	uint8_t		possbl_pos;

	parse_init(unrnkng_champ_names, &n);
	i = parse_set_splited_argv(&splited_argv, argv);
	while (splited_argv[i])
	{
		if (update_limit_number(0) > MAX_PLAYERS - 1)
			exit_error(E_ARGV_LIMIT_PLAYERS);
		if ((possbl_pos = parse_n_flag(splited_argv + i)) && i++ && i++)
			parse_champ_name(splited_argv[i - 2], &champ_names[possbl_pos - 1]);
		else
			parse_champ_name(splited_argv[i], &unrnkng_champ_names[n++]);
		i++;
		update_limit_number(1);
	}
	merge_champ_names(champ_names, unrnkng_champ_names);
	check_missed_pos_order();
	if (splited_argv != argv)
		ft_arrdel((void ***)&splited_argv);
}
