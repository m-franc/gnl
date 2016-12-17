# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfranc <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 18:43:40 by mfranc            #+#    #+#              #
#    Updated: 2016/12/17 13:23:22 by mfranc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

SRCS = 	ft_memset.c				\
		ft_bzero.c 				\
		ft_memcpy.c				\
		ft_memccpy.c 			\
		ft_memmove.c			\
		ft_memchr.c				\
		ft_memcmp.c				\
		ft_strlen.c				\
		ft_strdup.c				\
		ft_strcpy.c				\
		ft_strncpy.c			\
		ft_strcat.c				\
		ft_strncat.c			\
		ft_strlcat.c			\
		ft_strchr.c				\
		ft_strrchr.c			\
		ft_strstr.c				\
		ft_strnstr.c			\
		ft_strncmp.c			\
		ft_strcmp.c				\
		ft_atoi.c				\
		ft_isalpha.c			\
		ft_isdigit.c			\
		ft_isalnum.c			\
		ft_isprint.c			\
		ft_isascii.c			\
		ft_toupper.c			\
		ft_tolower.c			\
		ft_memalloc.c			\
		ft_memdel.c				\
		ft_strnew.c				\
		ft_strdel.c				\
		ft_strclr.c				\
		ft_striter.c			\
		ft_striteri.c			\
		ft_strmap.c				\
		ft_strmapi.c			\
		ft_strequ.c				\
		ft_strnequ.c			\
		ft_strsub.c				\
		ft_strjoin.c			\
		ft_strtrim.c			\
		ft_putstr.c				\
		ft_puttab.c				\
		ft_strsplit.c			\
		ft_putnbr.c				\
		ft_itoa.c				\
		ft_intlen.c				\
		ft_putendl.c			\
		ft_putchar_fd.c			\
		ft_putchar.c			\
		ft_putstr_fd.c			\
		ft_putendl_fd.c			\
		ft_putnbr_fd.c			\
		ft_lstnew.c				\
		ft_lstdelone.c			\
		ft_lstdel.c				\
		ft_lstadd.c				\
		ft_lstiter.c			\
		ft_lstmap.c				\
		ft_countword.c			\
		ft_isword.c				\
		ft_tabnew.c				\
		ft_range.c				\
		ft_sqrt.c				\
		ft_strsplit_tolist.c	\
		ft_putlist.c			\
		ft_listcount.c

	
OBJECTS = 	ft_memset.o				\
			ft_bzero.o 				\
			ft_memcpy.o				\
			ft_memccpy.o 			\
			ft_memmove.o			\
			ft_memchr.o				\
			ft_memcmp.o				\
			ft_strlen.o				\
			ft_strdup.o				\
			ft_strcpy.o				\
			ft_strncpy.o			\
			ft_strcat.o				\
			ft_strncat.o			\
			ft_strlcat.o			\
			ft_strchr.o				\
			ft_strrchr.o			\
			ft_strstr.o				\
			ft_strrchr.o			\
			ft_strnstr.o			\
			ft_strncmp.o			\
			ft_strcmp.o				\
			ft_atoi.o				\
			ft_isalpha.o			\
			ft_isdigit.o			\
			ft_isalnum.o			\
			ft_isprint.o			\
			ft_isascii.o			\
			ft_toupper.o			\
			ft_tolower.o			\
			ft_memalloc.o			\
			ft_memdel.o				\
			ft_strnew.o				\
			ft_strdel.o				\
			ft_strclr.o				\
			ft_striter.o			\
			ft_striteri.o			\
			ft_strmap.o				\
			ft_strmapi.o			\
			ft_strequ.o				\
			ft_strnequ.o			\
			ft_strsub.o				\
			ft_strjoin.o			\
			ft_strtrim.o			\
			ft_putstr.o				\
			ft_puttab.o				\
			ft_strsplit.o			\
			ft_putnbr.o				\
			ft_itoa.o				\
			ft_intlen.o				\
			ft_putendl.o			\
			ft_putchar_fd.o			\
			ft_putchar.o			\
			ft_putstr_fd.o			\
			ft_putendl_fd.o			\
			ft_putnbr_fd.o			\
			ft_lstnew.o				\
			ft_lstdelone.o			\
			ft_lstdel.o				\
			ft_lstadd.o				\
			ft_lstiter.o			\
			ft_lstmap.o				\
			ft_countword.o			\
			ft_isword.o				\
			ft_tabnew.o				\
			ft_range.o				\
			ft_sqrt.o				\
			ft_strsplit_tolist.o	\
			ft_putlist.o			\
			ft_listcount.o		

all: $(NAME)

$(NAME) : $(OBJECTS)
	ar rc $@ $^
	ranlib $@

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
