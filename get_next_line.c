/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 14:32:21 by mfranc            #+#    #+#             */
/*   Updated: 2016/12/11 19:06:23 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char		buf[BUFF_SIZE + 1];
	char			*tmp;

	if ()line 	
	tmp = strdup(*line);
	while (read(fd, buf, BUFF_SIZE) >= 0)
	{
		buf[BUFF_SIZE] = '\0';
		tmp = ft_strjoin(tmp, buf);
		ft_putendl(tmp);
		if (ft_strchr(buf, '\n') != NULL)
		{
			tmp[ft_strlen(tmp) - 1] = '\0';
			*line = ft_strdup(tmp);
			if (!(ft_strchr(buf, *(buf + 1))))
				return (0);
			return (1);
		}
	}
	return (-1);
}
