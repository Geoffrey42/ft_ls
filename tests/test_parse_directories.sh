#!/bin/sh

#gcc -Wall -Wextra -Werror test_parse_directories.c ../src/parser.c ../src/parse_flags.c ../src/parse_directories.c ../display_errors.c ../inc/ft_ls.h ../libft/libft.a

echo "TROISIEME SERIE : tests de parse_directories\n"
echo "test 1 : ./a.out -a -t -- d1 d2\n"
./a.out -a -t -- d1 d2
echo "test 2 : ./a.out -a -t -r -- d1 d2\n"
./a.out -a -t -r -- d1 d2
echo "test 3 : ./a.out -a -t d1 d2\n"
./a.out -a -t d1 d2
echo "test 4 : ./a.out -- d1 d2\n"
./a.out -- d1 d2
echo "test 5 : ./a.out d1 d2\n"
./a.out d1 d2
echo "test 6 : ./a.out\n"
