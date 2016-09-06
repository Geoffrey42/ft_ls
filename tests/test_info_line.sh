#!/bin/sh

#clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
#clang -o test_info_line main.o -I libft/includes -L libft/ -lft
make re && make clean
gcc -Wall -Wextra -Werror test_info_line.c ../src/parser.c ../inc/ft_ls.h ../libft/libft.a

echo "PREMIERE SERIE\n\n"
echo "test 1 : ./a.out d1 d2\n"
./a.out d1 d2 
echo "\ntest 2 : ./a.out -f1 -f2\n"
./a.out -f1 -f2 
echo "\ntest 3 : ./a.out -f1 -f2 d1 d2\n"
./a.out -f1 -f2 d1 d2 
echo "\ntest 4 : ./a.out -f1 -f2 -- d1 d2\n"
./a.out -f1 -f2 -- d1 d2 
echo "\ntest 5 : ./a.out\n"
./a.out
rm a.out

gcc -Wall -Wextra -Werror test_parse_flags.c ../src/parser.c ../src/parse_flags.c ../src/display_errors.c ../inc/ft_ls.h ../libft/libft.a

echo "DEUXIEME SERIE\n\n"
echo "test 1 : ./a.out\n"
./a.out 
echo "test 2 : ./a.out -a\n"
./a.out -a
echo "test 3 : ./a.out -a -t -r\n"
./a.out -a -t -r
echo "test 4 : ./a.out -a -t -r -l -R\n"
./a.out -a -t -r -l -R
echo "test 5 : ./a.out -aaaaaaaaaat\n"
./a.out -aaaaaaaaaat
echo "test 6 : ./a.out -a -t -z -l -R\n"
./a.out -a -t -z -l -R
echo "test 7 : ./a.out -a -t -r -l -R -- -z\n"
./a.out -a -t -r -l -R -- -z
echo "test 8 : ./a.out --\n"
./a.out --
rm a.out
