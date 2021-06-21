#ifndef TEST_H
#define TEST_H
/* do check for car sup and client*/
#include "Car.h"
#include "Supplier.h"
#include "Client.h"
#include <string.h>
#include<stdio.h> 
#include <stdlib.h>

void run_clients_test();
void run_clients_test2();
void run_clients_test3();
void print_prompt(char *text);
void add_example_clients(Tree *cl);
void run_clients_and_cars_test();
void run_test_car();
void run_suppliers_test();
#endif
