gcc -Wall -Wextra -Werror tests_if_dir.c inc/*.h src/sort_content.c src/call_back_functions.c src/display.c src/sort_directories.c libft/libft.a
mkdir d1 d2
touch f1 f2
./a.out f1 d2 f2 d1
rm -rf d1 d2 f1 f2 a.out
