/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 14:32:21 by mfranc            #+#    #+#             */
/*   Updated: 2016/12/16 20:50:17 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
int				save_lines(char **tmp, char **line)
{
	size_t		lenline;

	//ft_putendl(*line);
	if (ft_strchr(*line, '\n') != NULL)
	{
		lenline = ft_strlen(*line) - ft_strlen(ft_strchr(*line, '\n'));
		*line = ft_strsub(*tmp, 0, lenline);
		*tmp = ft_strchr(*line, '\n') + 1;
		return (1);
	}
	return (0);
}

int				ft_read(int fd, char **tmp, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			ret;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		*line = ft_strjoin(*tmp, buf);
		if (save_lines(tmp, line) == 1)
			return (1);
	}
	if (ret < 0)
		return (-1);
	if (*line != NULL)
		return (1);
	return (save_lines(tmp, line));
}

int				get_next_line(int fd, char **line)
{
	static char	*tmp;

	if (!fd || !line)
		return (-1);
	*line = NULL;
	return (ft_read(fd, &tmp, line));
}
