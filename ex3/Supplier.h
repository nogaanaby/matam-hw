//declare functions, 
//global variables use outside the class declare, 
//and types

#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#define GENDER_MALE=0
#define GENDER_FEMALE=1
#define GENDER_OTHER=2
#define MAX_GRADE_SIZE=13
#define NOT_GRADED=-1

struct Student {
  char first_name[16];
  char last_name[16];
  unsigned int gender;
  int id[9];
  float lab_grades[13];
};
struct Student create_student(char first_name[], char last_name[], int id[],unsigned int gender);
struct Student update_lab_grade(struct Student* stu,unsigned int lab_number, float grade);
struct Student print_student(struct Student* stu);
#endif

