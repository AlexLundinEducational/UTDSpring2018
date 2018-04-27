//Alex Lundin
//AML140830@utdallas.edu
//SE 3377.501 - CC++ in  UNIX
#ifndef PROGRAM4_H
#define  PROGRAM4_H
#include <cstdio>
#include <map>
#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string> 
#include <stdlib.h>
#include <cstdlib>
extern int yyparse();
extern int yylex();
extern int yylineno();
extern char* yytext();
extern std::map <int, std::string> myMap;
using namespace std;
void Scanner(std::string);
void Parser(std::string);
char* fileRead (std::string inputFileName);
void fileWrite (std::string outputFileName, char* cPointer);
void coutPipe (std::string outPutFile);
std::string callCommand (std::string command);
enum myEnums {INFILE,OUTFILE,UFLAG,LFLAG};
#endif // PROGRAM4_H

