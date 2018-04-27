#include "program3.h"

void parseCmdLine (int, char **);
void DoWork ();
map <int, string> myMap;
int main(int argc, char * argv[]);
int main (int argc, char * argv[]){

        parseCmdLine(argc, argv);
	DoWork();
	return(0);
}
