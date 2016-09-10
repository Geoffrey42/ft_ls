#gcc -Wall -Wextra -Werror test_parse_flags.c ../src/parser.c ../src/parse_flags.c ../src/parse_directories.c ../src/display_errors.c ../inc/ft_ls.h ../libft/libft.a

echo "DEUXIEME SERIE : tests de parse_flags\n"
echo "test 1 : ./a.out"
./a.out
echo "test 2 : ./a.out -a"
./a.out -a
echo "test 3 : ./a.out -a -t -r"
./a.out -a -t -r
echo "test 4 : ./a.out -a -t -r -l -R"
./a.out -a -t -r -l -R
echo "test 5 : ./a.out -aaaaaaaaaat"
./a.out -aaaaaaaaaat
echo "test 6 : ./a.out -a -t -z -l -R"
./a.out -a -t -z -l -R
echo "test 7 : ./a.out -a -t -r -l -R -- -z"
./a.out -a -t -r -l -R -- -z
echo "test 8 : ./a.out --"
./a.out --
