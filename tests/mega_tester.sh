#!/bin/sh

#gcc -Wall -Wextra -Werror ./test_info_line.c ../src/parser.c ../inc/ft_ls.h ../src/parser_flags.c ../src/display_errors.c ../src/parser_directories.c ../libft/libft.a
#./test_info_line.sh
#rm a.out

#gcc -Wall -Wextra -Werror test_parse_flags.c ../src/parser.c ../src/parser_flags.c ../src/parser_directories.c ../src/display_errors.c ../inc/ft_ls.h ../libft/libft.a
#./test_parse_flags.sh
#rm a.out

#gcc -Wall -Wextra -Werror test_parse_directories.c ../src/parser.c ../src/parser_flags.c ../src/parser_directories.c ../src/display_errors.c ../inc/ft_ls.h ../libft/libft.a
#./test_parse_directories.sh
#rm a.out

#gcc -Wall -Wextra -Werror test_parse_prompt.c ../src/parser.c ../src/parser_flags.c ../src/parser_directories.c ../src/display_errors.c ../inc/ft_ls.h ../libft/libft.a
#./test_parse_prompt.sh
#rm a.out

gcc -Wall -Wextra -Werror test_create_directories_list.c ../src/create_data_dir.c ../src/display_errors.c ../src/merge_sort.c ../src/parser.c ../src/parser_directories.c ../src/parser_flags.c ../src/list_directories.c ../src/test_functions.c ../src/compare_list_data.c ../inc/ft_ls.h ../libft/libft.a
./test_create_directories_list.sh
#rm a.out
