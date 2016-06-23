#!/bin/sh
gcc tests_parser.c src/parser.c src/display.c src/info_line.c inc/ft_ls.h libft/libft.a
echo "tests sur parseur\n"
echo "test 1 : ./a.out -a src\n"
./a.out -a src
echo "\ntest 2 : ./a.out -l -t\n"
./a.out -l -t
echo "\ntest 3 : ./a.out -a -r -l -R -t tests src\n"
./a.out -a -r -l -R -t tests src
echo "\ntest 4 : ./a.out -arlRt\n"
./a.out -arlRt
echo "\ntest 5 : ./a.out -ttttttt libft\n"
./a.out -ttttttt libft
echo "\ntest 6 : ./a.out -arrrrrrrrrrrlRt\n"
./a.out -arrrrrrrrrrrrrrrrrrlRt
echo "\ntest 7 : ./a.out -arlRt -- -z\n"
./a.out -arlRt -- -z
echo "\ntest 8 : ./a.out -arlRtz\n"
./a.out -arlRtz
echo "\ntest 9 : ./a.out -a --\n"
./a.out -a --
echo "\ntest 10 : ./a.out -a -r -- bbb aaa\n"
./a.out -a -r -- bbb aaa
echo "\ntest 11 : ./a.out -a -r bbb aaa\n"
./a.out -a -r bbb aaa
echo "\ntest 12 : ./a.out -a -r -- bbb aaa libft\n"
./a.out -a -r -- bbb aaa libft
echo "\ntest 13 : ./a.out -a -r -- tests aaa libft bbb\n"
./a.out -a -r -- tests aaa libft bbb
rm a.out
echo "\n\t---------------\n"
gcc test_sort_directories.c src/info_line.c src/parser.c src/display.c src/sort_directories.c src/call_back_functions.c  inc/ft_ls.h libft/libft.a
echo "tests sur dossiers en parametre de ft_ls\n"
echo "test 1 : ./a.out -t tests src libft\n"
./a.out -t tests src libft
echo "test 2 : ./a.out inc Makefile libft tests_parser.c compile_test_parses.sh inspect_file tests src test_sort_directories.c\n"
./a.out inc Makefile libft tests_parser.c compile_test_parses.sh inspect_file tests src test_sort_directories.c
echo "test 3 : ./a.out -r inc Makefile libft tests_parser.c compile_test_parses.sh inspect_file tests src test_sort_directories.c\n"
./a.out -r inc Makefile libft tests_parser.c compile_test_parses.sh inspect_file tests src test_sort_directories.c
echo "test 4 : ./a.out -t inc Makefile libft tests_parser.c compile_test_parses.sh inspect_file tests src test_sort_directories.c\n"
./a.out -t inc Makefile libft tests_parser.c compile_test_parses.sh inspect_file tests src test_sort_directories.c
echo "test 5 : ./a.out -rt inc Makefile libft tests_parser.c compile_test_parses.sh inspect_file tests src test_sort_directories.c\n"
./a.out -rt inc Makefile libft tests_parser.c compile_test_parses.sh inspect_file tests src test_sort_directories.c
rm a.out
echo "\n\t---------------\n"
