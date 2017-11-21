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
