# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggane <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/04 11:16:35 by ggane             #+#    #+#              #
#    Updated: 2016/09/08 20:35:49 by ggane            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
CC = gcc -Wall -Werror -Wextra
SRC = src/*.c
OBJ = *.o
INC = ./inc/

all: $(NAME)

$(NAME):
		make -C libft/ fclean && make -C libft/
		$(CC) -I$(INC) -I./libft/ -c $(SRC)
		$(CC) $(OBJ) -o $(NAME) -I libft/includes -L libft/ -lft
clean:
		rm -f $(OBJ)
fclean: clean
		rm -f $(NAME)
re:	fclean all
