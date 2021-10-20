
// author: Connor Oaks
// date: October 19, 2021

#include <windows.h> 
#include <string.h>
#include <unistd.h> 
#include <sys/types.h>
#include <sys/stat.h> 
#include <limits.h>
#include <stdio.h>

#define PARENT_DIR "C:\\Oakshell" 
#define BIN_DIR "\\bin\\" 

struct stat st = {0}; 

int main() {
	// create directories if they do not yet exist. 
	char install_dir[sizeof(PARENT_DIR) + sizeof(BIN_DIR)];
	strcpy(install_dir, PARENT_DIR);
	strcat(install_dir, BIN_DIR);
	if(stat(PARENT_DIR, &st) == -1) {
		mkdir(PARENT_DIR);  
		mkdir(install_dir); 
	}
	// build bin path based off of current working directory.
	char bin_path[PATH_MAX];
	getcwd(bin_path, sizeof(bin_path)); 
	strcat(bin_path, BIN_DIR);
	// construct copy command and pass to Windows. 
	char cmd[PATH_MAX * 2]; 
	strcpy(cmd, "copy "); 
	strcat(cmd, bin_path); 
	strcat(cmd, " "); 
	strcat(cmd, install_dir); 
	printf("%s\n", cmd);
	system(cmd); 
	getchar(); 
	// TODO: Add to environment PATH
	return 0; 
}