/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfranc <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 14:15:18 by mfranc            #+#    #+#             */
/*   Updated: 2017/01/04 19:51:43 by mfranc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# define BUFF_SIZE 10

#include <fcntl.h>
#include "libft/libft.h"

int		get_next_line(const int fd, char **line);

typedef struct			s_file
{
	char				*tmp;
	int					fd;
	struct s_file		*next;
}						t_file;


#endif
