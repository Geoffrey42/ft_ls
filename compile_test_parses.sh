#!/bin/sh
gcc tests_parser.c src/parser.c src/display.c inc/ft_ls.h libft/libft.a
echo "tests sur parseur\n"
echo "test 1 : ./a.out -a src\n"
./a.out -a src
echo "\ntest 2 : ./a.out -l -t\n"
./a.out -l -t
echo "\ntest 3 : ./a.out -a -r -l -R -t tests src\n"
./a.out -a -r -l -R -t tests src
echo "\ntest 4 : ./a.out -arlRt\n"
./a.out -arlRt
echo "\ntest 5 : ./a.out -ttttttt\n"
./a.out -ttttttt
echo "\ntest 6 : ./a.out -arrrrrrrrrrrlRt\n"
./a.out -arrrrrrrrrrrrrrrrrrlRt
echo "\ntest 7 : ./a.out -arlRt -- -z\n"
./a.out -arlRt -- -z
echo "\ntest 8 : ./a.out -arlRtz\n"
./a.out -arlRtz
rm a.out
echo "\n\t---------------\n"
#gcc test_sort_directories.c src/sort_directories.c src/call_back_functions.c inc/ft_ls.h libft/libft.a
#echo "tests sur dossiers en parametre de ft_ls\n"
#echo "test 1 : ./a.out\n"
#./a.out
#echo "test 2 : ./a.out aaa\n"
#./a.out aaa
#echo "test 3 : ./a.out aaa aa\n"
#./a.out aaa aa
#echo "test 4 : ./a.out bbb aaa\n"
#./a.out bbb aaa
#echo "test 5 : ./a.out aaa AAA\n"
#./a.out aaa AAA
#echo "test 6 : ./a.out ccc bbb aaa\n"
#./a.out ccc bbb aaa
#echo "test 7 : ./a.out -a -r bbb aaa\n"
#./a.out -a -r bbb aaa
#echo "test 8 : ./a.out -a -r -- bbb aaa\n"
#./a.out -a -r -- bbb aaa
#echo "test 9 : ./a.out -a -r -- bbb aaa libft\n"
#./a.out -a -r -- bbb aaa libft
#echo "test 10 : ./a.out -a -r -- tests aaa libft bbb\n"
#./a.out -a -r -- tests aaa libft bbb
#rm a.out
#echo "\n\t---------------\n"
