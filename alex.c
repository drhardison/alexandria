//C Library of Alexandria

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>  
#include "alex.h"

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
