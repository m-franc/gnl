/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 14:32:21 by mfranc            #+#    #+#             */
/*   Updated: 2017/01/03 19:25:13 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

t_file	*lstnew(int fd)
{
	t_file	*new;

	if (!(new = (t_file*)malloc(sizeof(t_file))))
		return (NULL);
	new->fd = fd;
	new->tmp = NULL;
	new->next = NULL;
	return (new);
}

t_file	*get_file(t_file **begin, int fd)
	/*{
	  t_file	*tmplst;
	  t_file	*tmpnext;

	  if (!*begin)
	  return (*begin = lstnew(fd));
	  tmplst = (*begin);
	  tmpnext = (*begin)->next;
	  if (tmplst->fd == fd)
	  return (tmplst);
	  while (tmplst)
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
	 tmpnext->next = lstnew(fd);
	 return (tmpnext->next);
	 }*/
{
	t_file	*tmplst;

	if (!*begin)
		return (*begin = lstnew(fd));
	tmplst = *begin;
	while (tmplst && fd != tmplst->fd)
		tmplst = tmplst->next;
	if (tmplst == NULL)
	{
		tmplst = *begin;
		while (tmplst->next)
			tmplst = tmplst->next;
		tmplst->next = lstnew(fd);
		return (tmplst->next);
	}
	return (tmplst);
}

int				save_lines(char *ndtmp, t_file **file, char **line)
{
	if ((*file)->tmp[0] == '\0')
		return (0);
	if (ndtmp == NULL)
	{
		*line = ft_strdup((*file)->tmp);
		(*file)->tmp = NULL;
		return (1);
	}
	else
	{	
		*line = ft_strsub((*file)->tmp, 0, ft_strlen((*file)->tmp) - ft_strlen(ndtmp));
		(*file)->tmp = ndtmp + 1;
		return (1);
	}
}

int				ft_read(t_file **file, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			ret;
	char		*tmpline;
	char		*ndtmp;

	if (!((*file)->tmp))
		(*file)->tmp = ft_strnew(0);
	ndtmp = ft_strchr((*file)->tmp, '\n');
	while (!ndtmp || *((*file)->tmp))
	{
		if ((ret = read((*file)->fd, buf, BUFF_SIZE)) == 0)
			break ;
		if (ret < 0)
			return (-1);
		buf[ret] = '\0';
		tmpline = ft_strjoin((*file)->tmp, buf);
		ft_strdel(&(*file)->tmp);
		(*file)->tmp = tmpline;
		ndtmp = ft_strchr((*file)->tmp, '\n');
	}
	return (save_lines(ndtmp, file, line));
}

int				get_next_line(const int fd, char **line)
{
	static t_file	*file;

	if (!line)
		return (-1);
	file = get_file(&file, fd);
	*line = NULL;
	return (ft_read(&file, line));
}
