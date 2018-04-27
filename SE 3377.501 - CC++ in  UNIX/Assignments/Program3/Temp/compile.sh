#!/bin/bash
echo compiling
g++ -I ./include/ -c program2.cc
g++ -I ./include -c  parsecmdline.cc
g++ -I ./include -c dowork.cc
echo compile complete
echo Linking files to create executable
g++  program2.o parsecmdline.o dowork.o -o hw2
echo Link Complete
echo Done 
exit 0

