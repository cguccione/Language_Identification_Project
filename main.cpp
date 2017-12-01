#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "data_freq.h"
using namespace std;

int main(int argc, char *argv[]){
	if (argc != 2){
		//cerr << "Please provide a valid string" << endl;
		exit(EXIT_FAILURE);
	}
	std::string data_input = argv[1];
	DF item = DF(argv[1]);
	std::string out = item.getData();
	std::vector<std::string> tri_vec = item.dataTrig();
	//for (int x=0; x<((int) tri_vec.size()); x++){
	//	std::cout << tri_vec[x] << std::endl;
	//}
	std::string freq = item.trigFreq(tri_vec);
	std::cout << freq << std::endl;
}
