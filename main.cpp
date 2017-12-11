#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "data_freq.h"
#include <math.h>
#include <sstream>
using namespace std;

int main(int argc, char *argv[]){
	
	/*Tests to make sure there are two arguments in the command line,
	otherwise will exit with code 1 */
	if (argc < 2){
		exit(EXIT_FAILURE);
	}
	
	/*Takes the input data from the command line and tests to see if the input data is readable,
	if it is, then sorts the final file into a string named test_data and all the remaning files
	into a vector of strings called traning_data.
	*/
	std::vector<int> test_vec_of_ele; 
	std::string test_data;
	std::vector<std::string> training_data;
	//Tests to see if the input data is readable
	for (int i=1; i<argc; i++){
		ifstream myfile(argv[i]);
		if (myfile.fail()){
			exit(EXIT_FAILURE);
		}
		else{
			if (i == (argc-1)){
				ifstream inFile;
				inFile.open(argv[i]);
				stringstream strStream;
				strStream << inFile.rdbuf();
				string str = strStream.str();
				DF test_lang= DF(str);
				std::string test_lang_out = test_lang.getData();
				test_vec_of_ele = test_lang.dataElements();
			}
			else {
				ifstream inFile;
				inFile.open(argv[i]);
				stringstream strStream;
				strStream << inFile.rdbuf();
				string str = strStream.str();
				training_data.push_back(std::string(str));
			}
		}
	}

	//Makes the data input into a DF object
	double most_sim =0;
	int sim_count =1;
	int most_sim_count=1;
	for (int x=0; x<((int) training_data.size()); x++){
		DF lang =DF(training_data[x]);
		std::string lang_out = lang.getData();
		std::vector<int> vec_of_ele = lang.dataElements();
		long long top =0;
		double b1 =0;
		double b2=0;
	//		std::cout << test_vec_of_ele[37875974] << std::endl;
		long long ab1=0;
		long long ab2=0;
		for (int i=0; i<((int)vec_of_ele.size()); i++){
			top+=(vec_of_ele[i] * test_vec_of_ele[i]);
		}	
	//	std::cout << vec_of_ele[(int)vec_of_ele.size() -2] << std::endl;
	//	std::cout << test_vec_of_ele[(int) vec_of_ele.size() -2] << std::endl;
//		std::cout << "here3" << std::endl;
		for (int i=0; i<((int)vec_of_ele.size()); i++){
			ab1+=((vec_of_ele[i])*(vec_of_ele[i]));
		}
		b1=sqrt(ab1);
		for (int i=0; i<((int)test_vec_of_ele.size()); i++){
			ab2+=((test_vec_of_ele[i])*(test_vec_of_ele[i]));
		}
		b2=sqrt(ab2);
		double similarity=((top)/(b1*b2));
		if (most_sim < similarity){
			most_sim= similarity;
			most_sim_count=sim_count;
		}
		sim_count+=1;
	}
//	std::cout << most_sim_count << std::endl;
	std::cout << argv[most_sim_count] << std::endl;
}
