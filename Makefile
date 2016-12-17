# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfranc <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/17 12:24:32 by mfranc            #+#    #+#              #
#    Updated: 2016/12/17 13:37:33 by mfranc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = test_gnl

FW = -Wall -Wextra -Werror

FA = -g -fsanitize=address

FLAGS = $(FW) $(FA)

CC = clang

SRC = get_next_line.c main.c

DIR_LIB = libft/

OBJ = $(SRC:%.c=%.o)

LIB = $(DIR_LIB)includes

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $@ $(OBJ) -I $(LIB) -L $(DIR_LIB) -lft
	
%.o: %.c
	$(CC) $(FW) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
