#!/bin/bash
touch _ex1.txt;
echo camille > _ex1.txt;
ln -s _ex1.txt _ex1_1.txt;
ln -s _ex1.txt _ex1_2.txt;
ls -i > ex1.txt