# Language_Identification_Project
CSC 211 Final Project

Problems to Solve:
1. Check to see that exactly one command line argument was taken
	a.If this is not true, the program will exit with a non-zero return code	
		Need a ERROR_CATCHING bool function with if loop to test this
	b.It may print to STDERR 
		Solve this by using cerr
2. Check to see that file contains only lowercase a-z space, (� �) and newline characters
	a.If this is not true, the program will exit with nonzero result code
		Need to add another ERROR_CATCHING2 bool function with an if loop to test this
	b.It may print to STDERR
		Solve this by using cerr
3. Split the data into trigrams 
	a.Create a str function DATA_to_TRIG
		Uses the same idea from the translate function from DNA project
		The function outputs a vector of strings of trigrams 
4. Find the frequencies of trigrams
	a.Create a int function TRIG_to_FREQ
		Take the vector from the DATA_to_FREQ as an input
		Maps the input digit, ex. �a� to its corresponding letter ex. �1�
		Use a for loop to go through each letter in the trigram and multiply by appropriate 27^x number
		Ex. aaa = 27x^3*1 + 27x^2*1 + 27x *1, then output this value
5.Creates a DATA_FREQ class takes a set of data and outputs trigram frequency vector
	a.Uses the DATA_to_TRIG, TRIG_to_FREQ functions
6.Separate and runs the test and Training Data
	a.Creates a function that returns nothing called TEST_vs_TRAIN
	b.Has an if statement that splits the test data from the training data
	The training data is run through the DATA_FREQ class 
	The test data is also run through the DATA_FREQ class
	Each result of the training data is compared to the 
		test data using the SIM function (listed below) then, 
		the resulting float is put into a vector along with the name of the training data
7.Create a SIM function
	a.Takes two vectors and outputs an float between 0 and 1
	b.Uses the cosine similarity function included in the packet
8.Compare Similar Values
	a.Creates a new function called SORT_SIM that finds the highest number in the list of training data and then outputs the name of that language

Files to Create:
1.Need to download all the training data and create appropriate files named after that language
2.Need to download the  test file containing the mystery language
3.Create a data_freq.cpp file for the class
4.Create a maine.cpp file for the rest of the code

Main() Structure for Milestone 1:
1.Apply both error catching functions: ERROR_CATCHING and ERROR_CATCHING2
2.Creates a similar class to one listed above which uses the DATA_to_TRIG and TRIG_to_FREQ functions
3.This data is then being placed into a vector that lines up with the order listed on the grade sheet

Main() Structure for Milestone 2:
1.Apply everything from Milestone 1, except edit the class so 
	that is like the one in the original outline not the one from Milestone 1
2.Apply the TEST_vs_TRAIN function
3.Apply the SIM function
4.Apply this SORT_SIM function

Libraries Needed:
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <vector>

File Compile Script Will Compile:
main.cpp 
data_freq.cpp

