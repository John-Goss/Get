# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgosset <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/11 16:41:02 by vgosset           #+#    #+#              #
#    Updated: 2016/01/12 14:38:14 by jle-quer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	main.c \
		get_next_line.c

OBJ = $(SRC:.c=.o)

LIB_DIR = libft/

NAME = Get_Next

FLAG = -Wall -Wextra -Werror

CC = gcc

all : $(NAME)

LIB = libft.a

$(NAME) : $(OBJ) $(LIB)
	$(CC) $(FLAG) $(OBJ) -L $(LIB_DIR) -lft -I$(LIB_DIR) -o $(NAME)
%.o:%.c
	$(CC) $(FLAG) -c $< -o $@
$(LIB) :
	make -C $(LIB_DIR)
clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
