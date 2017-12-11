#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <vector>
#include "data_freq.h"
#include <math.h>

/*Default Constructor*/
DF::DF(){
	data="";
}

/*If the data contains file that is not a lowercase letter (a-z), a space or a new line charcter then exits with an error. Else it will add the data to org_data.*/
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

/*Splits the data into all trigram possiblities and then turns each trigram into an element
and outputs these elements into a master vector */
std::vector<int> DF::dataElements(){
	//Creates an empty vector with 19683 places
	std::vector<int> frequinces(19683);
	std::string temp_tri;
	std::string alpha= " abcdefghijklmnopqrstuvwxyz";
	int temp_num;

	//Breaks the data into sets of three or trigrams and adds them to temp_tri 
	for (int x=0; x<=(((int)(data.length())-3)); x++){
		temp_tri="";
		temp_num=0;
		for (int y=0; y<3; y++){
			temp_tri+=data[x+y];
		}

		//Goes through each letter in temp_tri and converts it to an element
		for (int z=0; z<3; z++){
			for (int c=0; c<27; c++){
				if (temp_tri[z] == alpha[c]){
					temp_num += c*(pow (27.0, (2-z)));
				}
			}
		}
		//Adds one to the total the place in which the above element sits in the master frequinces vector
		frequinces [temp_num]+=1;	
	}
	//Returns the final vector with all the trigrams in the data set comapred too
	return frequinces;
}
