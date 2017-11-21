# Language_Identification_Project
CSC 211 Final Project

Problems to Solve:
1. Check to see that exactly one command line argument was taken
	a.If this is not true, the program will exit with a non-zero return code	
		Need a ERROR_CATCHING bool function with if loop to test this
	b.It may print to STDERR 
		Solve this by using cerr
2. Check to see that file contains only lowercase a-z space, (‘ ‘) and newline characters
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
		Maps the input digit, ex. ‘a’ to its corresponding letter ex. ‘1’
		Use a for loop to go through each letter in the trigram and multiply by appropriate 27^x number
		Ex. aaa = 27x^3*1 + 27x^2*1 + 27x *1, then output this value
