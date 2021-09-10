#!/bin/sh

for i in {1..10}
do
gcc ./main.c -o main; ./main
done
