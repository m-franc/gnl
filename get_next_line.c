/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 14:32:21 by mfranc            #+#    #+#             */
/*   Updated: 2016/12/16 23:19:41 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int				save_lines(char **tmp, char **line)
{
	size_t		lenline;
	char		*stop;

	stop = ft_strchr(*tmp, '\n');
	if (ft_strlen(stop) > 0)
	{
		lenline = ft_strlen(*line) - ft_strlen(stop);
		*line = ft_strsub(*line, 0, lenline);
		*tmp = ft_strdup(stop + 1);
		return (1);
	}
	else
		return (1);
	return (0);
}

int				ft_read(int fd, char **tmp, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			ret;

	printf("TMP APRES UN GNL : %s\n", *tmp);
	while (ft_strchr(*line, '\n') != NULL)
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret < 0)
			return (-1);
		buf[ret] = '\0';
		*line = ft_strjoin(*tmp, buf);
	}
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
