#!/bin/bash
echo camille > _ex3.txt;
chmod a-x _ex3.txt >> ex3.txt;
chmod ao=rwx _ex3.txt >> ex3.txt;
chmod -R g=u _ex3.txt >> ex3.txt

