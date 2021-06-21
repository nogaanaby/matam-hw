#include "Utils.h"
#include "Supplier.h"
int size_k = 0;
int count_index = 0;

Tree *createSuppliersTree()
{
    return createTree();
}

/* remove from file only test */
void get_Supplier__test(Supplier *Supplier_)
{
    static int i = 1;
    int phone = 73312356;
    sprintf(Supplier_->id, "%d", 12345 + i);
    sprintf(Supplier_->phone_number, "%d", phone + i);
    Supplier_->count_transactions = 10 + i;
    Supplier_->sum_of_total_transactions_price = 100 * i;
    if (i == 1 || i == 3)
    {
        Supplier_->name = my_strdup("jeep");
    }
    else
    {
        Supplier_->name = my_strdup("nisan");
    }
    i++;
}

/* add a new Supplier to array of Supplier = > 1.check for this Supplier in data 2.find the pleace in array 
 3. return error if in array */
int addNewSupplier(Tree *tree)
{
   return addNewNode(tree,createSupplier,compereSupplier);
}

unsigned int compereSupplier(Node *node1,Node *node2){
       if(node1==NULL || node2==NULL){
        return -2;
    }else{
        Supplier* sup2=node2->value;
        Supplier* sup1=node1->value;
        if(sup1->id < sup2->id){
            return 1;
        }else if(sup1->id > sup2->id){
            return -1;
        }else{
            return 0;
        }
    }
}

void createSupplier(Node *new_node){
    Supplier *new_supplier = (Supplier*) malloc(sizeof(Supplier));
    get_Supplier__test(new_supplier);
    new_node->value = new_supplier;
}

int get_supplier_input_from_user(struct Supplier *temp_sup)
{
    if (temp_sup)
    {
        get_chr_input("Please enter (10 digit) sup id number:\t", temp_sup->id, TEN);
        get_int_input("Please enter (10 digit) supplier sum of transactions:\t", &temp_sup->sum_of_total_transactions_price, TEN);
        get_int_input("Please enter (5 digit) amount of transaction:\t", &temp_sup->count_transactions, FIVE);
        get_chr_input("Please enter (10 digit) sup phone number:\t", temp_sup->phone_number, TEN);
        /* alloc name memory  */
        get_chr_input("Please enter (10 digit) sup name:\t", temp_sup->name, ALLOC);
        temp_sup->is_empty = 0;
        printf("\n");
        printf(" add new supplier \n");
        return 1;
    }
    return 0;
}


/* 
int averageOfSupplierMoney(Tree *tree)
{
    if (tree)
        return (averageOfSupplierMoney_REC(tree->root) / tree->elementCount);
    return -1;
}

int averageOfSupplierMoney_REC(Node *node)
{

    if (node == NULL)
    {
        return 0;
    }

    return node->value->sum_of_total_transactions_price + averageOfSupplierMoney_REC(node->left) + averageOfSupplierMoney_REC(node->right);
}
 */

void print_sup(Node *node,int count)
{
    Supplier *sup =  node->value; 
    count = 0 ; 
    printf("Supplier name:\t%s\n", (sup)->name);
    printf("Supplier phone number:\t%s\n", (sup)->phone_number);
    printf("Supplier id :\t%s\n", (sup)->id);
    printf("supplier sum of transactions:\t%d\n", (sup)->sum_of_total_transactions_price);
    printf("number of transactions:\t%d\n\n", (sup)->count_transactions);
}

void print_sup_Tree(Tree *tree)
{
    printtree_rec(tree->root,0,print_sup);
}

Node *FindSupInTreeByid(Node *node, char *sup_id)
{
    Node *left = NULL, *right = NULL;
    Supplier *sup = (Supplier*)node->value; 
    if (node == NULL || strcmp(sup->id,sup_id) == 0)
    {
        return node;
    }
    left = FindSupInTreeByid(node->left,sup_id);
    right = FindSupInTreeByid(node->right,sup_id);
    return left ? left : right;
    /*start with the root  if it`s not me go left and then go right*/
}

/* delete all Supplier */
void DeleteAllSuppliers(Tree *tree)
{
    if (tree == NULL)
    {
        freeTree(tree->root,free_Suppliers);
        tree->root = NULL;       
    }
}


void free_Suppliers(Node *sup)
{
    Supplier *sup_temp ; 
    sup_temp = sup->value;
    free(sup_temp->name);
}

