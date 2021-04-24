#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include "Client.h"
#include "Supplier.h"
#include "IO.h"

//loop->
// suzukycar   seachBy(arr*, manufactor name, suzuky)

int main(){

    printf("please type the supplier id: ");
    char buf_id[TEN];
    scanf("%s \n",&buf_id);
    struct Supplier nisan=addNewSupplier(&buf_id,);
    
}