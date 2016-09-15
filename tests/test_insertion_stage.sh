#!/bin/sh

echo "\nSIXIEME SERIE : tests de insertion_phase\n\n"
echo "test 1 : ./a.out\n"
./a.out
echo "\ntest 2 : ./a.out -a\n"
./a.out -a
echo "\ntest 3 : ./a.out -a --\n"
./a.out -a --
echo "\ntest 4 : ./a.out -a ../src\n"
./a.out -a ../src
echo "\ntest 5 : ./a.out -a ../src ../inc\n"
./a.out -a ../src ../inc
echo "\ntest 6 : ../a.out -a -t -- ../src ../inc\n"
./a.out -a -t -- ../src ../inc
echo "\ntest 7 : ../a.out -a -t -- ../src ../inc ../tests\n"
./a.out -a -t -- ../src ../inc ../tests
echo "\ntest 8 : ../a.out -a -t -- ../src ../inc ../tests\n"
./a.out -a -t -- ../src ../inc ../tests
echo "\ntest 9 : ../a.out -a -t -- ../src ../inc ../tests  " 
./a.out -a -t -- ../src ../inc ../tests   
