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

#include "../includes/asm.h"

int		main(int ac, char **av)
{
	t_data	cw;

	if (ac == 1)
		ft_exit(USAGE);
	ft_check_filename(av[ac - 1]);
	if ((cw.read_fd = open(av[ac - 1], O_RDONLY)) < 3)
	{
		close(cw.read_fd);
		ft_exit("Bad file read\n");
	}
	if (read(cw.read_fd, NULL, 0) < 0)
	{
		close(cw.read_fd);
		ft_exit("Bad file read\n");
	}
	ft_init_structs(&cw, get_number_of_lines(&cw, -1));
	lseek(cw.read_fd, 0, 0);
	ft_read_file(&cw);
	ft_cor_extension(av[ac - 1], &cw);
	if ((cw.write_fd = open(cw.file, O_RDWR | O_CREAT | O_TRUNC, 0666)) == -1)
		ft_exit("Unable to create .cor file\n");
	writing_to_file(&cw, cw.write_fd);
	ft_close_fd(cw.read_fd, cw.write_fd, cw.file);
	free_data(&cw);
	return (0);
}
