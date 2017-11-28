#ifndef _data_freq_h
#define _data_freq_h

#include <iostream>
#include <string>
#include <vector>

/*
A class to reperesent the trigram frequencies resulting from the input data
A DF object has one member fields: the data, which was orginally inputed,

*****************This is what you want your class to do put is not actually for this header comment
the trigrams , which
is the data split into all the possible groupings of three, and the trigram frequenices which is the 
number of times that a trigram is present in the orgrinal data set. 
*/

class DF {

public:
	/*
	Default constructor
	*/
	DF();

	/*
	Constructor with an argument for input data
	If data contains invalid characters, throws a std::runtime_error  
	*/
	DF(std:: string data);

	/*
	Getter methods
	*/
	std::string getData();

	/*
	QUESTION: Do we need to input data for dataTrig
	Splits the data into all the possible trigram possiblities and then outputs
	them into a vector.
	*/
	std::vector<std::string> dataTrig();
	
	/*
	Take the vector of strings trigram strings and the outputs their frequencies in 
	a list of strings	
	*/
	std::string trigFreq();

};

#endif
