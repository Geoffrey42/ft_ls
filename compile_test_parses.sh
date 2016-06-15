#!/bin/sh
gcc tests_parser.c src/parser.c src/display.c inc/ft_ls.h libft/libft.a
echo "tests sur parseur\n"
echo "./a.out -a\n"
./a.out -a
echo "./a.out -a -r -l -R -t\n"
./a.out -a -r -l -R -t
echo "./a.out -arlRt\n"
./a.out -arlRt
echo "./a.out -arrrrrrrrrrrlRt\n"
./a.out -arrrrrrrrrrrrrrrrrrlRt
echo "./a.out -arlRt -- -z\n"
./a.out -arlRt -- -z
echo "./a.out -arlRtz\n"
./a.out -arlRtz
rm a.out
echo "\n\t---------------\n"
gcc test_sort_directories.c src/sort_directories.c src/call_back_functions.c inc/ft_ls.h libft/libft.a
echo "tests sur dossiers en parametre de ft_ls\n"
echo "./a.out\n"
./a.out
echo "./a.out inc\n"
./a.out inc
echo "./a.out inc src\n"
./a.out inc src
echo "./a.out -a -r src inc\n"
./a.out -a -r src inc
echo "./a.out -a -r -- inc src\n"
./a.out -a -r -- inc src
echo "./a.out -a -r -- inc src libft\n"
./a.out -a -r -- inc src libft
echo "./a.out -a -r -- tests src libft inc\n"
./a.out -a -r -- tests src libft inc
rm a.out
