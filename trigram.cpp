#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <vector>
#include "data_freq.h"

/*Default Constructor*/
DF::DF(){
	data="";
}

/*If data contains file that is not a lowercase letter (a-z), a space or a new line charcter then exits with an error. Else it will add the data to org_data.
*/
DF::DF(std::string org_data){
	for (int x=0; x<((int)(org_data.length())); x++){
		if(org_data[x] != tolower(org_data[x]) && org_data[x] != ' ' && org_data[x] != '\n'){
			exit(EXIT_FAILURE);
		}
	}
	data=org_data;
}

/*Getter Method that grabs the data*/
std::string DF::getData(){
	return data;
}

/*Splits the data into all trigram possiblities and then outputs them into a vector*/
std::vector<std::string> DF::dataTrig(){
	std::vector<std::string> tri_vec;
	std::string temp;
	//Breaks the data into sets of three or trigrams and then adds these to tri_vec
	for (int x=0; x<=(((int)(data.length())-3)); x++){
		temp="";
		for (int y=0; y<3; y++){
			temp+=data[x+y];
		}
		tri_vec.push_back(temp);
	}
	return tri_vec;
}

/* Takes the vector of trigram strings and outputs their frequencies in a string */
std::string DF::trigFreq(std::vector<std::string> tri_vec){
	std::string freq;
	std::vector<std::string> test_vec;
	std::string alpha= " abcdefghijklmnopqrstuvwxyz";
	std::string temp="";
	int count;
	//Creates a generic vector of trigram frequinces that we can compare too called test_vec
	for (int x=0; x<27; x++){
		for (int y=0; y<27; y++){
			for (int q=0; q<27; q++){
				temp+=alpha[x];
				temp+=alpha[y];
				temp+=alpha[q];
				test_vec.push_back(temp);
				temp="";
			} 
		}	
	}
	//Tests each item in the test_vec with the items inside the tri_vec vector
	for (int c=0; c<19683; c++){
		count=0;
		for (int u=0; u<((int)(tri_vec.size())); u++){
			if (test_vec[c]==tri_vec[u]){
				count+=1;
			}			
		}
		//If the element from the test_vec matches the one with tri_vec then 
		//instead of adding a 0 adds the number of times that trigram is present
		freq+=std::to_string(count);
		freq+=" ";
	} 
	return freq;
}

