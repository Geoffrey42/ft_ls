#!/bin/sh

#clang -Wall -Wextra -Werror -I libft/includes -o test/*.o -c test*.c
clang  -Wall -Wextra -Werror -I libft/includes -o tests/main.o -c tests/main.c
clang -o compare_ls tests/main.o -I libft/includes -L libft/ -lft
touch lstest
touch ft_lstest 
echo "\n\t----------test 1----------\n"
echo "test avec ls -1 :\n"
ls -1 > lstest
./ft_ls > ft_lstest
./compare_ls lstest ft_lstest
echo "\n\t----------test 2----------\n"
echo "test avec ls -1a :\n"
ls -1a > lstest
./ft_ls -1a > ft_lstest
./compare_ls lstest ft_lstest
echo "\n\t----------end !!----------\n"
rm lstest ft_lstest compare_ls
