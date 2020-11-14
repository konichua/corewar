/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburnett <marvin@.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:30:26 by mburnett          #+#    #+#             */
/*   Updated: 2020/10/19 23:33:33 by mburnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_del_line(char *s)
{
	char	*buf;

	buf = ft_strchr(s, '\n');
	if (!buf)
		return (NULL);
	buf++;
	buf = ft_strdup(buf);
	if (buf)
	{
		free(s);
		s = NULL;
		return (buf);
	}
	return (NULL);
}

static char	*ft_first_str(char *dst)
{
	size_t	i;
	char	*buf;

	i = 0;
	if (!*dst)
		return (NULL);
	while (dst[i] != '\0' && dst[i] != '\n')
		i++;
	buf = ft_strnew(i);
	if (!buf)
		return (NULL);
	ft_strncpy(buf, dst, i);
	return (buf);
}

int			get_next_line(const int fd, char **line)
{
	int			rd;
	static char	*descriptors[FD_MAX];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;

	if (fd < 0 || !line || fd > FD_MAX)
		return (-1);
	if (!descriptors[fd])
		descriptors[fd] = ft_strnew(1);
	while (!ft_strchr(descriptors[fd], '\n')
			&& (rd = read(fd, buf, BUFF_SIZE)) != 0)
	{
		if (rd < 0)
			return (-1);
		buf[rd] = '\0';
		tmp = ft_strjoin(descriptors[fd], buf);
		free(descriptors[fd]);
		descriptors[fd] = tmp;
	}
	*line = ft_first_str(descriptors[fd]);
	if (!*line && rd == 0)
		return (0);
	descriptors[fd] = ft_del_line(descriptors[fd]);
	return (1);
}
