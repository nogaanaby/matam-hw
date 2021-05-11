#ifndef TEST_H
#define TEST_H
/* do check for car sup and client*/
#include "car.h"
#include "Supplier.h"
#include<stdio.h>

void print_prompt(char *text);
void print_cars(struct Car *list_car);
void run_test_car(struct Car *list);
void run_test_supplier(struct Supplier* list_car);

#endif