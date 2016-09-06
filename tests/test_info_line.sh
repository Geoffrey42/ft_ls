#!/bin/sh

#clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
#clang -o test_info_line main.o -I libft/includes -L libft/ -lft
make re && make clean
gcc -Wall -Wextra -Werror test_info_line.c ../src/parser.c ../inc/ft_ls.h ../libft/libft.a

echo "test 1 : ./a.out d1 d2\n"
./a.out d1 d2 
echo "\ntest 2 : ./a.out -f1 -f2\n"
./a.out -f1 -f2 
echo "\ntest 3 : ./a.out -f1 -f2 d1 d2\n"
./a.out -f1 -f2 d1 d2 
echo "\ntest 4 : ./a.out -f1 -f2 -- d1 d2\n"
./a.out -f1 -f2 -- d1 d2 
rm a.out
