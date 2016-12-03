/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 14:32:21 by mfranc            #+#    #+#             */
/*   Updated: 2016/12/03 16:20:02 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_ret(char c)
{
	if (c == '\n')
		return (1);
	else if (c == '\0')
		return (0);
	else
		return (2);
}

char	*ft_strsub_untilret(char *buf)
{
	static char	*bufinal;
	int			i;

	i = 0;
	while (ft_ret(buf[i]) != 0 || ft_ret(buf[i]) != 1)
	{
		bufinal[i] = buf[i];
		i++;
	}
	bufinal[i] = '\0';
	return (bufinal);
}

int		ft_read(int fd, char **line)
{
	int 		i;
	char		buf[BUFF_SIZE + 1];
	int			ret;

	i = 0;
	ret = read(fd, buf, BUFF_SIZE);
	buf[ret] = '\0';
	while (buf[i])
	{
		*line = ft_strsub_untilret(buf);
		if (ft_ret(buf[i]) == 1)
			return (1);
		else if (ft_ret(buf[i]) == 0)
			return (0);
		i++;
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int			get_next_line;

	get_next_line = ft_read(fd, line);
	if (get_next_line == 1)
		return (1);
	else if (get_next_line == 0)
		return (0);
	return (0);
}      
