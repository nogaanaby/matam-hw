//declare functions, 
//global variables use outside the class declare, 
//and types

#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

#define TEN 10
#define FIVE 5


struct Supplier {
  char id[TEN];
  char name[FIVE];
  char phone_number[TEN];
  int count_transactions;
  int sum_of_total_transactions_price;
};

// create array of Suppliers with stdin input M , set the fildes to zero 
int createSuppliersList(struct Supplier* sup);

// add a new car to array of cars = > 1.check for this car in data 2.find the pleace in array 
// 3. return error if in array 
 struct Supplier* addNewSupplier(char* id[],char name[], char phone_number[],
 int count_transactions,int sum_of_total_transactions_price);

// sarch for cars in data base 
 struct Supplier* searchBy( struct Supplier* sup, char attr[], char* value);

// delte car cy id number
int deleteSupplier(char* Supplier_id);

// delete all cars 
int deleteAllSuppliers();


#endif

