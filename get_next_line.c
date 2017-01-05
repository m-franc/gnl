/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 14:32:21 by mfranc            #+#    #+#             */
/*   Updated: 2017/01/05 15:14:12 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

t_file				*lstnew(t_file **begin, int fd)
{
	t_file			*new;

	if (!*begin)
	{
		if (!(*begin = (t_file*)malloc(sizeof(t_file))))
			return (NULL);
		(*begin)->fd = fd;
		(*begin)->tmp = ft_strnew(0);
		(*begin)->next = NULL;
	}
	if (!(new = (t_file*)malloc(sizeof(t_file))))
		return (NULL);
	new->fd = fd;
	new->tmp = ft_strnew(0);
	new->next = (*begin);
	return (new);
}

t_file				*get_file(t_file **begin, int fd)
{
	t_file			*tmplst;
	t_file			*tmpnext;

	if (!*begin)
		return (*begin = lstnew(begin, fd));
	if ((*begin)->fd == fd)
		return (*begin);
	tmplst = *begin;
	tmpnext = (*begin)->next;
	while (tmpnext)
	{	
		if (tmpnext->fd == fd)
		{
			tmplst->next = tmpnext->next;
			tmpnext->next = (*begin)->next;
			*begin = tmpnext;
			return (tmpnext);
		}
		tmplst = tmplst->next;
		tmpnext = tmpnext->next;
	}
	return (lstnew(begin, fd));
}

void				remove_file(t_file **file)
{
	t_file	*supp;

	supp = *file;
	if ((*file)->next)
	{
		supp->fd = -1;
		*file = (*file)->next;
		free(supp);
	}
	else
	{
		supp->fd = -1;
		free(supp);
		supp = NULL;
	}
}

int					save_lines(char *ndtmp, t_file **file, char **line)
{
	if ((*file)->tmp[0] == '\0')
	{
		remove_file(file);	
		return (0);
	}
	if (ndtmp == NULL)
	{
		*line = ft_strdup((*file)->tmp);
		(*file)->tmp[0] = '\0';
		return (1);
	}
	else
	{	
		*line = ft_strsub((*file)->tmp, 0, ft_strlen((*file)->tmp) - ft_strlen(ndtmp));
		(*file)->tmp = ndtmp + 1;
		return (1);
	}
}

int					get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				ret;
	char			*tmpline;
	char			*ndtmp;
	static t_file	*file;

	if (!line)
		return (-1);
	file = get_file(&file, fd);
	*line = NULL;
//	printf("\033[31mTMP VOIR SI LE MFD MARCHE : %s\n", (file)->tmp);
	ndtmp = ft_strchr(file->tmp, '\n');
	while (!ndtmp || *((file)->tmp))
	{
		if ((ret = read(file->fd, buf, BUFF_SIZE)) == 0)
			break ;
		if (ret < 0)
			return (-1);
		buf[ret] = '\0';
		tmpline = file->tmp;
		file->tmp = ft_strjoin(tmpline, buf);
		ft_strdel(&tmpline);
		ndtmp = ft_strchr(file->tmp, '\n');
	}
	return (save_lines(ndtmp, &file, line));
}
