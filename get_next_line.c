/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 14:32:21 by mfranc            #+#    #+#             */
/*   Updated: 2016/12/12 21:15:52 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		ft_strlenuntilret(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int		save_lines(char *buf, char *tmp, char **line)
{
	if (ft_strchr(buf, '\n') != NULL || ft_strchr(buf, '\0') == buf)
	{
		*line = ft_strsub(tmp, 0, ft_strlenuntilret(tmp));
		printf("\nline choope: %s\n", *line);
		tmp = ft_strsub(tmp, ft_strlen(*line), ft_strlen(tmp) - ft_strlenuntilret(tmp));
		printf("\ntmp pour la suite : %s\n", tmp);
		return (1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char			*buf;
	int				ret;
	static char		*tmp;

	if (!fd || !line)
		return (-1);
	if (!(buf = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	*line = NULL;
	tmp = ft_strnew(1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0 && *line == NULL)
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(tmp, buf);
		ft_putendl(tmp);
		if (save_lines(buf, tmp, line) == 1)
			return (1);
	}
	if (ret < 0)
		return (-1);
	if (*line == NULL)
		return (0);
	return (1);
}
