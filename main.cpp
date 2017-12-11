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
			//Creates a object of the test data which then returns a test_vec_of_ele vector
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
			//Places all the trainning data into vector that is used later in the program
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

	//Sets counting variable to find the most similar set of data
	double most_sim =0;
	int sim_count =1;
	int most_sim_count=1;
	
	//Loops through the vector of tranning data and tests each lanuage
	for (int x=0; x<((int) training_data.size()); x++){

		//Creates an object for the lanuage and outputs the a vector
		//with it's element values
		DF lang =DF(training_data[x]);
		std::string lang_out = lang.getData();
		std::vector<int> vec_of_ele = lang.dataElements();

		//Sets all the variables used to calculte the cos similarity
		long long top =0;
		double b1 =0;
		double b2=0;
		long long ab1=0;
		long long ab2=0;

		//Calculates the cos similarity equation
		for (int i=0; i<((int)vec_of_ele.size()); i++){
			top+=(vec_of_ele[i] * test_vec_of_ele[i]);
		}	
		for (int i=0; i<((int)vec_of_ele.size()); i++){
			ab1+=((vec_of_ele[i])*(vec_of_ele[i]));
		}
		b1=sqrt(ab1);
		for (int i=0; i<((int)test_vec_of_ele.size()); i++){
			ab2+=((test_vec_of_ele[i])*(test_vec_of_ele[i]));
		}
		b2=sqrt(ab2);
		double similarity=((top)/(b1*b2));

		//Compares the similarity of the vectors and corrects the vector if needed	
		if (most_sim < similarity){
			most_sim= similarity;
			most_sim_count=sim_count;
		}
		sim_count+=1;
	}

	//Outputs the final language to the screen 
	std::cout << argv[most_sim_count] << std::endl;
}
