//Alex Lundin
//AML140830@utdallas.edu
//SE 3377.501 - CC++ in  UNIX
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdio>

std::string callCommand (const char* command, const char* arg1);
int main()
{
	const char* GAWK_LOCATION = "/mnt/hgfs/Programs/HW/Program3/bin/gawk %s";
	// header print
	std::cout << "\ngawk at: /mnt/hgfs/Programs/HW/Program3/bin/gawk" << std::endl;
	std::cout << "/mnt/hgfs/Programs/HW/Program3/bin/gawk --version" << std::endl;
	std::cout << "/mnt/hgfs/Programs/HW/Program3/bin/gawk -f gawk.code numbers.txt" << std::endl;
	
	std::string result;	
	
    // first command to run with popen
    const char* shellCall ("./Shellcmd1.sh");
	// start callCommand and return output into result
	result = callCommand(shellCall, GAWK_LOCATION);
	// print result
	std::cout << "\nThe first call to gawk returned:" << std::endl;
	std::cout << "\n" << result << std::endl;
	
    // second command to run with popen
    const char* shellCall2 ("./Shellcmd1.sh");
	// start callCommand and return output into result
	result = callCommand(shellCall2, GAWK_LOCATION);
	// print result
	std::cout << "\nThe second call to gawk returned: " << result << std::endl;

	
	// parse string by delimeter
	std::string s = result;
	std::string delimiter = " ";
	std::string firstColumnAccumulator = s.substr(0, s.find(delimiter));
	std::string secondColumnAccumulator = s.substr((1 + s.find(delimiter)),s.length());
	
	// print individual accumulators
	std::cout << "The sum of Column 1 is: " << firstColumnAccumulator << std::endl;
	std::cout << "The sum of Column 4 is: " << secondColumnAccumulator << std::endl;
	int int1 = atoi(firstColumnAccumulator.c_str());
	int int2 = atoi(secondColumnAccumulator.c_str());
	int sum = int1 + int2;
	std::cout << "The sum of the two numbers is: " << sum << std::endl;

    return 0;
}

std::string callCommand (const char* shellCall, const char* arg1){
	std::string result;	

	char command[200];
	snprintf(command, sizeof command, shellCall, arg1);
	
	// open read pipe
    FILE* pipe = popen(command, "r");
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