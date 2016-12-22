/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 14:32:21 by mfranc            #+#    #+#             */
/*   Updated: 2016/12/22 13:49:36 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int				save_lines(char *ndtmp, char **tmp, char **line)
{
	if (ndtmp == NULL)
	{	
		*line = ft_strdup(*line);
		**tmp = '\0';
		return (1);
	}
	else
	{
		*line = ft_strsub(*line, 0, ft_strlen(*line) - ft_strlen(ndtmp));
		*tmp = ndtmp + 1;
		return (1);
	}
}

int				ft_read(int fd, char **tmp, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			ret;
	char		*ndtmp;

	if (!*tmp)
		*tmp = "";
	*line = *tmp;
	ndtmp = ft_strchr(*line, '\n');
	while (!ndtmp || *tmp)
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) == 0)
			break ;
		buf[ret] = '\0';
		*line = ft_strjoin(*line, buf);
		ndtmp = ft_strchr(*line, '\n');
	}
	if (ret < 0)
		return (-1);
	if (ndtmp == NULL && **tmp == '\0')
		return (0);
	return (save_lines(ndtmp, tmp, line));
}

int				get_next_line(const int fd, char **line)
{
	static char	*tmp;

	if (!fd || !line)
		return (-1);
	*line = NULL;
	return (ft_read(fd, &tmp, line));
}
