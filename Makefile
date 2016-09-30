# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggane <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/04 11:16:35 by ggane             #+#    #+#              #
#    Updated: 2016/09/30 09:41:34 by ggane            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= ft_ls
SRC= src/compare_list_data.c \
	 src/compare_tree_data.c \
	 src/create_data_dir.c \
	 src/create_directories_list.c \
	 src/delete.c \
	 src/device.c \
	 src/display.c \
	 src/display_date.c \
	 src/display_errors.c \
	 src/display_size.c \
	 src/errors_traversal.c \
	 src/info_line.c \
	 src/insertion_stage.c \
	 src/long_format_flag_1.c \
	 src/long_format_flag_2.c \
	 src/main.c \
	 src/main_functions.c \
	 src/merge_sort.c \
	 src/parser_directories.c \
	 src/parser_flags.c \
	 src/recursive_flag.c \
	 src/test_functions_1.c \
	 src/test_functions_2.c \
	 src/traversal_stage.c \
	 src/traversal_stage_2.c 
CC= clang
CFLAGS= -Wall -Werror -Wextra
INC= inc/
OBJ= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		make -C libft/
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L libft/ -lft

%.o: %.c
		$(CC) $(CFLAGS) $< -c -o $@

clean:
		make -C libft/ clean
		rm -f $(OBJ)

fclean: clean
		make -C libft/ fclean
		rm -f $(NAME)

re: fclean all
