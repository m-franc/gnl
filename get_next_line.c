/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 14:32:21 by mfranc            #+#    #+#             */
/*   Updated: 2016/12/16 11:49:15 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int				save_lines(char **tmp, char **line/*, char **tmpline*/)
{
	size_t		lenline;

	ft_putendl(*tmp);
	if (ft_strchr(*tmp, '\n') != NULL)
	{
		lenline = ft_strlen(*tmp) - ft_strlen(ft_strchr(*tmp, '\n'));
		*line = ft_strsub(*tmp, 0, lenline);
		*tmp = ft_strchr(*tmp, '\n') + 1;
		return (1);
	}
	*line = ft_strdup(*tmp);
	if (**line != '\0')
		return (1);
//	ft_strdel(tmp);
	return (0);
}

int				ft_read(int fd, char **tmp, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			ret;
//	char		*tmpline;

	if (save_lines(tmp, line) == 1)
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		*tmp = ft_strjoin(*tmp, buf);
		if (save_lines(tmp, line/*, &tmpline*/) == 1)
			return (1);
	}
	if (ret < 0)
		return (-1);
	//if (ret == 0)
	//
	//return (1);
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char	*tmp;

	if (!fd || !line)
		return (-1);
	*line = NULL;
	if (tmp == NULL)
		tmp = ft_strnew(1);
	return (ft_read(fd, &tmp, line));
}
