/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corr_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_cor_extension(char *file, t_data *data)
{
	char	*filename;

	filename = ft_strsub(file, 0, ft_strlen(file) - 2);
	file = ft_strjoin(filename, ".cor");
	ft_strdel(&filename);
	data->file = ft_strdup(file);
	ft_strdel(&file);
}

void	ft_check_filename(char *name)
{
	if (ft_strlen(ft_strstr(name, ".s")) != 2)
		ft_exit("Bad file name\n");
}
