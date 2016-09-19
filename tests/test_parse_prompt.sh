#!/bin/sh

#gcc -Wall -Wextra -Werror test_parse_directories.c ../src/parser.c ../src/ ../src/parse_directories.c ../src/display_errors.c ../inc/ft_ls.h ../libft/libft.a

echo "QUATRIEME SERIE : tests de parse_prompt\n"
echo "test 1 : ./a.out -a -t -- src inc\n"
./a.out -a -t -- src inc
echo "test 2 : ./a.out -a -t -r -- src inc\n"
./a.out -a -t -r -- src inc
echo "test 3 : ./a.out -a -t src inc\n"
./a.out -a -t src inc
echo "test 4 : ./a.out -- src inc\n"
./a.out -- src inc
echo "test 5 : ./a.out src inc\n"
./a.out src inc
echo "test 6 : ./a.out -a -t -- src inc\n"
./a.out src inc
