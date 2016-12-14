/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 14:32:21 by mfranc            #+#    #+#             */
/*   Updated: 2016/12/14 18:21:36 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		save_lines(char **tmp, char *buf, char **line)
{
	size_t	lenline;

	*tmp = ft_strjoin(*tmp, buf);
	if (ft_strchr(*tmp, '\n') != NULL)
	{
		lenline = ft_strlen(*tmp) - ft_strlen(ft_strchr(*tmp, '\n'));
		*line = ft_strsub(*tmp, 0, lenline);
		*tmp = ft_strchr(*tmp, '\n') + 1;
		return (1);
	}
	return (0);
}

int		ft_read(int fd, char **tmp, char **line)
{
	char	*buf;
	int		ret;

	if (!(buf = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (save_lines(tmp, buf, line) == 1)
			return (1);
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0)
		return (save_lines(tmp, buf, line));
	else
		return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*tmp;
	int			read;

	if (!fd || !line)
		return (-1);
	*line = NULL;
	if (!(tmp))
		tmp = ft_strnew(1);
	read = ft_read(fd, &tmp, line);
	free(tmp);
	if (read == -1)
		return (-1);
	if (*line == NULL)
		return (0);
	return (1);
}
