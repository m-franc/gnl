/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 14:32:21 by mfranc            #+#    #+#             */
/*   Updated: 2016/12/04 19:58:06 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		get_next_line(int fd, char **line)
{
	int 			i;
	static char		buf[BUFF_SIZE + 1];
	int				ret;
	
	i = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)))
		buf[ret] = '\0';
	while (buf[i])
	{
		(*line)[i] = buf[i];
		if (buf[i] == '\0')
			return (0);
		if (buf[i] == '\n')
		{
			(*line)[i] = '\0';
			ft_putendl((*line));
			return (1);
		}
		i++;
	}
	return (2);
}
