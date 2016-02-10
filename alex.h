/***********************************************
* Authon: Joseph Hagan
* E-mail: joseph.m.hagan@wmich.edu
* Description: A multipurpose C library (header file)
*************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>  
#define true 1
#define false 0

typedef int bool;
typedef int boolean;

bool proceed(char *);  	// Asks user if he'd like to proceed.

void toUpper(char *, size_t); // Converts string to UpperCase
void toLower(char *, size_t); // Converts string to LowerCase

void println(char *); 	// Prints the string with \n added.
void printerr(char *);	// Prints the error string that you send it terminated with a \n.
void printerrno(int);	// Takes the errno, and prints the associated error with a \n.
void printint(char *, int, char *);	// An easy way to print a line with an int. You can put text before or after if you want.
void clear();	//Clears the terminal output to give you a fresh screen.
