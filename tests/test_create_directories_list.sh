#!/bin/sh

echo "\nCINQUIEME SERIE : tests de create_directories_list\n\n"
mkdir AAA ccc LLL error2
touch zzz xxx yyy iii
chmod -r error2 iii
echo "test 1 : ./a.out\n"
./a.out
echo "\ntest 2 : ./a.out -a\n"
./a.out -a
echo "\ntest 3 : ./a.out -a --\n"
./a.out -a --
echo "\ntest 4 : ./a.out -a AAA\n"
./a.out -a AAA
echo "\ntest 5 : ./a.out -a AAA ccc\n"
./a.out -a AAA ccc
echo "\ntest 6 : ../a.out -a -t -- AAA ccc\n"
./a.out -a -t -- AAA ccc
echo "\ntest 7 : ../a.out -a -t -- AAA ccc LLL\n"
./a.out -a -t -- AAA ccc LLL
echo "\ntest 8 : ../a.out -a -t -- AAA error1 ccc LLL\n"
./a.out -a -t -- AAA error1 ccc LLL
echo "\ntest 9 : ../a.out -a -t -- AAA zzz error1 xxx ccc yyy LLL iii error2" 
./a.out -a -t -- AAA zzz error1 xxx ccc yyy LLL iii error2 
chmod +r error2 iii
rm -rf AAA ccc LLL error2 zzz xxx yyy iii
