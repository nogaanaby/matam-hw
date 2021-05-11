#ifndef TEST_H
#define TEST_H
/* do check for car sup and client*/
#include "car.h"
#include "Supplier.h"
#include "Client.h"
#include<stdio.h>

void print_prompt(char *text);
void print_cars(struct Car *list_car);
void run_test_car(struct Car *list);
void run_test_supplier(struct Supplier* list_car);
void run_clients_test(struct Client* clients_list);
void run_clients_and_cars_test(struct Client* clients_list,struct Car* cars_list);
void fill_in_clients_list(struct Client* clients_list);
void fill_in_cars_list(struct Car* cars_list);
#endif