#ifndef PROGRAM2_H
#define  PROGRAM2_H

#include <tclap/CmdLine.h>
#include <tclap/SwitchArg.h>
#include <tclap/UnlabeledValueArg.h>
#include <tclap/ValueArg.h>
#include <tclap/Arg.h>

#include <map>
#include <string>
#include <stdio.h>
#include <iostream>
#include <string> 
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

void parseCmdLine(int, char **);
void doWork();
enum myEnums {INFILE,OUTFILE,UFLAG,LFLAG};
myEnums.INFILE = 0;
myEnums.OUTFILE = 1;
myEnums.UFLAG = 2;
myEnums.LFLAG = 3;
#endif // PROGRAM2_H

