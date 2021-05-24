#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


#define TEN 10
#define FIVE 5
#define MAX_STRING_SIZE

enum error {size_,negitive_,type_,NULL_};

int validateInput(char* data, int size,int fixedSize);
int validateInputInt(int data, int size);

void printError(int errorCode);

int get_chr_input(char text[],char *attr,int attr_size);
int get_int_input(char text[],int *attr,int attr_size);

#endif

