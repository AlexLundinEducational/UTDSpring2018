//Alex Lundin
//AML140830@utdallas.edu
//SE 3377.501 - CC++ in  UNIX

#include "program4.h"
extern int yyparse();
extern int yylex();
extern int yylineno();
extern char* yytext();
int main(void)
{
	// file names, for easy switch outs
	const std::string INPUT_FILE_NAME = "input.txt";
	const std::string OUTPUT_FILE_NAME = "output.txt";
	const std::string COUT_LOG = "cout.log";
	const std::string CERR_LOG = "cerr.log";
	
	// create relative file name strings
	std::string inputFile("./" + INPUT_FILE_NAME);
	std::string outputFile("./" + OUTPUT_FILE_NAME);
	std::string coutFile("./" + COUT_LOG);
	std::string cerrFile("./" + CERR_LOG);
	
	// header print for main
	std::cout << "\nInput at: " << std::endl;
	
	int ntoken, vtoken;
	
	ntoken = yylex();
	while (ntoken){
		printf("%d\n", ntoken);
		ntoken = yylex();
	}

    return 0;
}

/* void dummyFunc (){
	// cout and cerr redirects
	
	// cout
	std::ofstream cout_redirect_file(coutFile.c_str());
    // save output buffer of cout
    streambuf * cout_buffer = cout.rdbuf();
    // redirect output into file
    cout.rdbuf(cout_redirect_file.rdbuf());	
	
	// cerr
	std::ofstream cerr_redirect_file(cerrFile.c_str());

    // save output buffer of cerr
    streambuf * cerr_buffer = cerr.rdbuf();

    // redirect output into file
    cerr.rdbuf(cerr_redirect_file.rdbuf());	
	
	
	char* charPointer = fileRead(inputFile);

	std::cout << charPointer << std::endl;
	std::cerr << charPointer << std::endl;	
	
	
	// cout and cerr restores
	// restore old buffers
    cout.rdbuf(cout_buffer);
	cerr.rdbuf(cerr_buffer);
	
} */
std::string callCommand (std::string command){
	std::string result;	

	
	// open read pipe
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe)
    {
        std::cerr << "Couldn't start command." << std::endl;
        return 0;
    }
	
	// store pipe contents to character buffer, one line at a time
	// accumlate characters into string array
	char buffer[4096];
    while (fgets(buffer,4096, pipe) != NULL) {
        result += buffer;
    }
		
    int returnCode = pclose(pipe);

	return result;
}

void Scanner (std::string inputFile){

	

	
	return;

}

void Parser (std::string inputFile){

	return;

}

void coutPipe (std::string outPutFile){
	std::ofstream cout_redirect_file(outPutFile.c_str());

    // save output buffer of cout
    streambuf * cout_buffer = cout.rdbuf();

    // redirect output into file
    cout.rdbuf(cout_redirect_file.rdbuf());	
	
    // restore old buffer
    cout.rdbuf(cout_buffer);	
	return;
}

void cerrPipe (std::string outPutFile){
	std::ofstream cerr_redirect_file(outPutFile.c_str());

    // save output buffer of cerr
    streambuf * cerr_buffer = cerr.rdbuf();

    // redirect output into file
    cerr.rdbuf(cerr_redirect_file.rdbuf());	
	
    // restore old buffer
    cerr.rdbuf(cerr_buffer);	
	return;
}

void fileWrite (std::string outputFileName, char* cPointer){
	
	char * outputFileNameCString = new char [outputFileName.length()+1];
	std::strcpy (outputFileNameCString, outputFileName.c_str());

	
    ofstream stream;


    stream.open(outputFileNameCString);
    if( !stream ){
		std::cerr << "\nerror: Unable to open output file for writing." << std::endl; 
			exit(0);		
	}else{
    stream << cPointer << endl;
	}
	
	return;
}

char* fileRead (std::string inputFileName){
	
	char * inputFileNameCString = new char [inputFileName.length()+1];
	std::strcpy (inputFileNameCString, inputFileName.c_str());	
	
	
	FILE* pFile = fopen(inputFileNameCString, "r");
	if (pFile!=NULL)
	{
		// Determine file size
		fseek(pFile, 0, SEEK_END);
		size_t size = ftell(pFile);

		char* charPointer = new char[size];

		rewind(pFile);
		fread(charPointer, sizeof(char), size, pFile);
		fclose (pFile);
		return charPointer;
		
	}else
	{ 
		std::cerr << "\nerror: Unable to open input file for reading." << std::endl; 
			exit(0);
	}	
	
}