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

/*If data contains file that is not a lowercase letter (a-z), a space or a new line charcter then
throws a std::runtime_error
*/
DF::DF(std:: string data){
	for (int x=0; x<((int)(data.length())); x++){
		if(data[x] != tolower(data[x]) && data[x] != ' ' && data[x] != '\n'){
			std::runtime_error("String contains invalid characters");
		}
	}
}

/*Getter Method that grabs the data*/
std::string DF::getData(){
	return data;
}

/*Splits the data into all trigram possiblities and then outputs them into a vector*/
std::vector<std::string> DF::dataTrig(){
	std::string data;
	std::vector<std::string> tri_vec;
	std::string temp;
	for (int x=0; x<=(((int)(data.length())-3)); x++){
		temp="";
		for (int y=0; y<3; y++){
			temp+=data[x+y];
		}
		tri_vec+=temp;
	}
	return tri_vec;
}

/* Takes the vector of trigram strings and outputs their frequencies in a string */
std::string DF::tringFreq(){
	std::vector<std::string> tri_vec;
	std::string freq;
	std::vector<std::string> test_vec;
	std::string alpha= " abcdefghijklmnopqrstuvwxyz";
	std::string temp="";
	int count;
	//Creates a generic vector of trigram frequinces that we can compare too
	for (int x=0; x<27; x++){
		for (int y=0; y<27; y++){
			for (int q=0; q<27; q++){
				temp+=alpha[x];
				temp+=alpha[y];
				temp+=alpha[z];
				test_vec+=temp;
				temp="";
			} 
		}	
	}
	for (int c=0; c<19683; c++){
		count=0;
		for (int u=0; u<((int)(tri_vec.length())); u++){
			if (test_vec[c]==tri_vec[u]){
				count+=1
			}			
		}
		freq+=count;
	} 
	return freq;
}

