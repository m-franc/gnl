/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 14:32:21 by mfranc            #+#    #+#             */
/*   Updated: 2016/12/13 21:19:24 by mfranc           ###   ########.fr       */
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
/*
   char	*ft_split_lines(char **tab, char **tmp, char *line)
   {
   int		i;
   char	*newline;

   i = 0;
   while (tab[i])
   {
   if (ft_strcmp(tab[i], line) == 0)
   {
   free(line);	
   newline = tab[i + 1];
   }
   i++;
   }
   return (newline);
   }
   */

int		save_lines(char **tmp, char **line)
{
	if (ft_strchr(*tmp, '\n') != NULL)
	{
		*line = ft_strsub(*tmp, 0, ft_strlenuntilret(*tmp));
		*tmp = ft_memset(*tmp, 0, ft_strlenuntilret(*tmp));
		return (1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char		*buf;
	int			ret;
	static char	*tmp;

	if (!fd || !line)
		return (-1);
	if (!(buf = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	*line = NULL;
	if (!(tmp))
		tmp = ft_strnew(1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(tmp, buf);
		if (save_lines(&tmp, line) == 1)
			return (1);
	}
	if (ret < 0)
		return (-1);
	if (*line == NULL)
		return (0);
	return (1);
}
