//declare functions, 
//global variables use outside the class declare, 
//and types

#ifndef IO_H
#define IO_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define TEN 10
#define FIVE 5


struct IO {

};

char* setInput();

int validateInput();

void printError();

void printData();

#endif

