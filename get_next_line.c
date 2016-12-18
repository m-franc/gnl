/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 14:32:21 by mfranc            #+#    #+#             */
/*   Updated: 2016/12/17 20:25:39 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int				save_lines(char *ndtmp, char **tmp, char **line)
{
//	printf("TMP : %s\n", ndtmp);
//	printf("LINE : %s\n", *line);d
	if (*ndtmp != '\0')
	{
		*line = ft_strsub(*line, 0, ft_strlen(*line) - ft_strlen(ndtmp));
		*tmp = ndtmp;
		return (1);
	}
	// Pas mal a revoir avec la condition du while
	ft_strdel(tmp);
	returnn (0);
}

int				ft_read(int fd, char **tmp, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int		ret;
	char		*ndtmp;
	
	*line = ft_strjoin(*tmp, buf);
	if (save_lines(ndtmp, line, tmp) == 1)
	// CONDITION A RETRAVAILLER / BOUCLE INFINIS, une seule ligne gros buffer, tout sauf la derniere ligne (\0) avec petit buffer, surement a cause de la boucle infinis... Puis revoir pourquoi on a qune ligne en gros buffer, surement revoir saves lines. A demain
	while (ndtmp == NULL)
	{ 
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
		*line = ft_strjoin(*line, buf);
		ndtmp = ft_strchr(*line, '\n');
	}
	if (ret < 0)
		return (-1);
	return (save_lines(ndtmp, tmp, line));
}

int				get_next_line(int fd, char **line)
{
	static char	*tmp;

	if (!fd || !line)
		return (-1);
	*line = NULL;
	return (ft_read(fd, &tmp, line));
}
