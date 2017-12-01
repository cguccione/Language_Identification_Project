#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "data_freq.h"
using namespace std;

int main(int argc, char *argv[]){
	
	/*Tests to make sure there are two arguments in the command line,
	otherwise will exit with code 1 */
	if (argc != 2){
		exit(EXIT_FAILURE);
	}

	//Takes the input data from the command line and stores it in data_input
	std::string data_input = argv[1];
	
	//Makes the data input into a DF object
	DF item = DF(argv[1]);
	
	//Calls all the functions to get data and turn it into a string of frequinces
	std::string out = item.getData();
	std::vector<std::string> tri_vec = item.dataTrig();
	std::string freq = item.trigFreq(tri_vec);

	//Prints out the frequinces
	std::cout << freq << std::endl;
}
