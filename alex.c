/***********************************************
* Authon: Joseph Hagan
* E-mail: joseph.m.hagan@wmich.edu
* Description: A multipurpose C library (c file)
*************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>  
#include <unistd.h>
#include "alex.h"

bool proceed(char * prompt){

	while(true){
		fprintf(stdout, "%s", prompt);
		char * input = NULL;
		size_t inputSize = 0;
		int error = getline(&input, &inputSize, stdin);
		toLower(input, 1);
		char choice = input[0];
		if (error != -1){
			switch (choice){
				case 'y':
					return true;
					break;
				case 'n':
					return false;
					break;
				default:
					fprintf(stdout, "%s\n","Please type y or n."); 
					break;	
			}
		}
		else{
			fprintf(stderr, "Error Getting Input From User...\n");
			exit(0);
		}
	}
}

void toUpper(char *input, size_t length){
	int i;
	for(i=0; i<length; i++){
		input[i] = (char)(toupper(input[i]));
	} 
}

void toLower(char *input, size_t length){
        int i;
        for(i=0; i<length; i++){
                input[i] = (char)(tolower(input[i]));
        }     
}


void println(char * line){
	fprintf(stdout, "%s\n", line);
}

void printerr(char * line){
	fprintf(stderr, "%s\n", line);
}

void printerrno(int err){
	fprintf(stderr,"%s\n", strerror(err));
}

void printint(char * begin, int num, char * end){
	int size = sizeof(char) + sizeof(*begin) + sizeof(*end);
	char * line = (char *)malloc(size);
	int error = sprintf(line, "%s%d%s", begin, num, end);
	if(error>=0){
		fprintf(stdout, "%s\n", line);
	}
	else{
		printerr("Was Not Able To Print Int String. Double Check the Parameters.");
	}
}

void clear(){
	pid_t pid = fork();
	if (pid != 0) 
	{
		wait(NULL);
	} 
	else
	{
		execlp("clear","clear",(char *)0);
		exit(0);
	}
}
