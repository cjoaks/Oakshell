
// author: Connor Oaks
// date: October 19, 2021

#include "shell.h" 

int main(int argc, char* argv[]) {  
	return (argc > 1) ? execute(argv[1]) : run(); 
}