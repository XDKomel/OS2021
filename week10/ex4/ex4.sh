#!/bin/bash
mkdir tmp;
cd ./tmp;
touch file1;
touch file2;
ln file1 link1;
cd ../;
gcc main.c;
gcc a.out >> ex4.txt;