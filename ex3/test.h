#ifndef TEST_H
#define TEST_H
/* do check for car sup and client*/
#include "car.h"
#include "Linked_List_car.h"
#include "Supplier.h"
#include "Client.h"
#include <string.h>
#include<stdio.h>  
// void print_Welcome_prompt();
// void print_prompt(char *text);
// void print_cars(struct Car *list_car);
// void run_test_supplier(struct Supplier* list_sup);
//void run_test_car();
void run_clients_test();
void add_example_clients(Clients_List *cl);
// void run_clients_and_cars_test();
// void fill_in_clients_list(struct Client* clients_list);
// void fill_in_cars_list(struct Car* cars_list,struct Supplier* list_sup);

void run_suppliers_test();
void add_example_suppliers(Suppliers_List *sl);

#endif