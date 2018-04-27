
#include "program2.h"
using namespace std;
void parseCmdLine (int argc, char * argv []){

  cout << "\nIn parseCmdLine";


 

    

    try {  

		// Define the command line object, and insert a message
		// that describes the program. The "Command description message" 
		// is printed last in the help text. The second argument is the 
		// delimiter (usually space) and the last one is the version number. 
		// The CmdLine object parses the argv array based on the Arg objects
		// that it contains. 
		TCLAP::CmdLine cmd("Displays useage information and exits", ' ', "0.0");

		// Define a value argument and add it to the command line.
		// A value arg defines a flag and a type of value that it expects,
		// such as "-n Bishop".
		TCLAP::ValueArg<std::string> outputFileArg("o","outfile","<output file name>",true,"homer","string");

		// Add the argument outputFileArg to the CmdLine object. The CmdLine object
		// uses this Arg to parse the command line.
		cmd.add( outputFileArg );

		// Define a switch and add it to the command line.
		TCLAP::SwitchArg upperSwitchArg("u","uu","Convert all text to uppercase", cmd, false);

		// Define a switch and add it to the command line.
		TCLAP::SwitchArg lowerSwitchArg("l","lower","Convert all text to lowercase", cmd, false);

		TCLAP::UnlabeledValueArg<string>  inputFileNoLabel( "inputfile", "<input file name>", true ,"string" ,
							  "Input File", false );
		cmd.add( inputFileNoLabel );

		//Parse the argv array.
		cmd.parse( argc, argv );

		// Get the value parsed by each arg. 
		std::string inputFilePath = inputFileNoLabel.getValue();
		std::string outputFilePath = outputFileArg.getValue();
		bool upperCaseInput = upperSwitchArg.getValue();
		bool lowerCaseInput = lowerSwitchArg.getValue();

		map.insert(pair<int,string>(myEnums.INFILE, inputFilePath));
		map.insert(pair<int,string>(OUTFILE, outputFilePath));    
      
      
		// Do what you intend. 
			if ( upperCaseInput )
		{
			std::cout << "\nUpper case" << std::endl;
			map.insert(pair<int,string>((UFLAG, "true")));
			map.insert(pair<int,string>((LFLAG, "false"))); 		  
		}
		  
		// Do what you intend. 
			if ( lowerCaseInput )
		{
			std::cout << "\nLower case " << std::endl;
			map.insert(pair<int,string>((UFLAG, "false")));
			map.insert(pair<int,string>((LFLAG, "true")));  	
		}
		

      
      } 
      catch (TCLAP::ArgException &e)  // catch any exceptions
	{ 
		std::cerr << "\nerror: " << e.error() << " for arg " << e.argId() << std::endl; 
			return;
	}






  
  return;
}
