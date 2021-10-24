#!/bin/bash
mkdir ../week01;
echo camille > ../week01/file.txt;
link ../week01/file.txt _ex2.txt;
node=($(ls -i _ex2.txt));
link=($(find ../week01 -inum $node));
echo $link >> ex2.txt;
find ../week01 -inum $node -exec rm {} \; 