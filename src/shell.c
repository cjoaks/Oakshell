
// author: Connor Oaks 
// date: October 19, 2021

#include <stdlib.h> 
#include <unistd.h>
#include <stdio.h>
#include <string.h> 
#include <limits.h>
#include "shell.h"

#define INPUT_MAX 4096
#define ARGS_MAX 100

void help();

void help() {
	printf("Help me\n"); // TODO: write the help message
}

// description: The main loop; gets user input and delegates to execute_cmd
int run() {
	printf("-- Welcome to Oaksh --\n\tUse -help view a list of available commands, as well as other information.\n");
	char cwd_buf[PATH_MAX]; 
	char input_buf[INPUT_MAX];   
	while(1) {
		memset(cwd_buf, 0, sizeof(cwd_buf)); 
		memset(input_buf, 0, sizeof(input_buf)); 
		getcwd(cwd_buf, sizeof(cwd_buf)); 
		printf("%s\\<oaksh>: ", cwd_buf);
		fgets(input_buf, sizeof(input_buf) - 1, stdin); 
		if(strcmp(input_buf, "-quit\n") == 0) {
			break; 
		}
		execute(strtok(input_buf, "\n")); 
	}  
	return 0; 
}

// description: Tokenizes and executes the command entered by the user. 
int execute(char* cmd) {
	char* args[ARGS_MAX];
	int index = 0; 
	char* param = strtok(cmd, " "); 
	while(param != NULL) {
		args[index++] = param; 
		param = strtok(NULL, " "); 
	}
	// Core oaksh commands
	if(strcmp(args[0], "-help") == 0) {
		help();
	}
	else {
		system(cmd); 
	}
	return 0; 
}
