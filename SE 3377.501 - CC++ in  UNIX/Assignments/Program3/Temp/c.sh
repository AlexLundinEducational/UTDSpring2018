#Alex Lundin
#AML140830@utdallas.edu
#SE 3357.501 - C++ in UNIX#Alex Lundin
#!/bin/bash
echo Setting TEMPDIR environment variable to /scratch
echo Compiling file1.cc
g++ -std=c++11 -c file1.cc
echo Linking files to create executable hw3
g++ file1.o -o hw3
echo Done
./hw3
exit 0
