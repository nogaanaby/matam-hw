//declare functions, 
//global variables use outside the class declare, 
//and types

#ifndef IO_H
#define IO_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define TEN 10
#define FIVE 5

enum error {size_,negitive_,type_};


int validateInput(char* data,unsigned int size);
int validateInputInt(int data,unsigned int size);
void printError(int errorCode);


#endif

