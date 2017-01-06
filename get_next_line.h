/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 14:15:18 by mfranc            #+#    #+#             */
/*   Updated: 2017/01/05 16:47:30 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# define BUFF_SIZE 1

#include <fcntl.h>
#include "libft/libft.h"

typedef struct			s_file
{
	char			*tmp;
	int			fd;
	struct s_file		*next;
}				t_file;

int				get_next_line(const int fd, char **line);
int				save_lines(char *ndtmp, t_file **file, char **line);
void				remove_file(t_file **file);
t_file				*get_file(t_file **file, int fd);
t_file				*lstnew(t_file **begin, int fd);

#endif
