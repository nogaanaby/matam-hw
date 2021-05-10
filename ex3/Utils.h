//declare functions, 
//global variables use outside the class declare, 
//and types

#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>


#define TEN 10
#define FIVE 5

enum error {size_,negitive_,type_};

int validateInput(char* data,unsigned int size,int fixedSize);
int validateInputInt(int data,unsigned int size);

void printError(int errorCode);

int get_chr_input(char text[],char *attr,int attr_size);
int get_int_input(char text[],int *attr,int attr_size);

#endif

