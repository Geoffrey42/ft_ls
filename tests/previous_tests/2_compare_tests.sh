#!/bin/sh
make re && make clean
echo "tests comparant ft_ls au vrai ls\n"
gcc tests_compare.c src/info_line.c src/parser.c src/display.c src/sort_directories.c src/call_back_functions.c src/sort_content.c inc/ft_ls.h libft/libft.a
touch lstest
touch ft_lstest 
echo "\n\t----------test 1----------\n"
echo "test avec ls -1 :\n"
ls -1 > lstest
./ft_ls > ft_lstest
./a.out lstest ft_lstest
echo "\n\t----------test 2----------\n"
echo "test avec ls -1r :\n"
ls -1r > lstest
./ft_ls -r > ft_lstest
./a.out lstest ft_lstest
echo "\n\t----------test 4----------\n"
echo "test avec ls -1a :\n"
ls -1a > lstest
./ft_ls -a > ft_lstest
./a.out lstest ft_lstest
echo "\n\t----------test 5----------\n"
echo "test avec ls -1ra :\n"
ls -1ra > lstest
./ft_ls -ra > ft_lstest
./a.out lstest ft_lstest
echo "\n\t----------test 6----------\n"
echo "test avec ls -1t :\n"
ls -1t > lstest
./ft_ls -t > ft_lstest
./a.out lstest ft_lstest
echo "\n\t----------test 7----------\n"
echo "test avec ls -1tr :\n"
ls -1tr > lstest
./ft_ls -tr > ft_lstest
./a.out lstest ft_lstest
#echo "\n\t----------test 8----------\n"
#echo "test avec ls -l :\n"
#ls -l > lstest
#./ft_ls -l > ft_lstest
#./a.out lstest ft_lstest
#echo "\n\t----------test 9----------\n"
#echo "test avec ls -rl :\n"
#ls -lr > lstest
#./ft_ls -lr > ft_lstest
#./a.out lstest ft_lstest
#echo "\n\t----------test 10---------\n"
#echo "test avec ls -R :\n"
#ls -1R > lstest
#./ft_ls -R > ft_lstest
#./a.out lstest ft_lstest
#echo "\n\t----------test 11---------\n"
#echo "test avec ls -Rr :\n"
#ls -1Rr > lstest
#./ft_ls -Rr > ft_lstest
#./a.out lstest ft_lstest
#echo "\n\t----------end !!----------\n"
#rm lstest ft_lstest a.out 
