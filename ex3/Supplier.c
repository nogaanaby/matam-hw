#include "Utils.h"
#include "Supplier.h"
int size_k = 0;
int count_index = 0;

Suppliers_Tree *createSuppliersTree()
{
    Suppliers_Tree *new_Tree = (Suppliers_Tree *)malloc(sizeof(Suppliers_Tree));
    if (new_Tree == NULL)
    {
        printf("error tree is empty\n");
        return NULL;
    }
    else
    {
        new_Tree->root = NULL;
        new_Tree->elementCount = 0;
        return new_Tree;
    }
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
int addNewSupplier(Suppliers_Tree *sup_Tree)
{
    Supplier_Node *new_supplier_node = (Supplier_Node *)malloc(sizeof(Supplier_Node));
    Supplier *new_supplier = (Supplier *)malloc(sizeof(Supplier));
    if (new_supplier && new_supplier_node && sup_Tree)
    {
        get_supplier_input_from_user(new_supplier);
        new_supplier_node->supplier = new_supplier;
        new_supplier_node->left = NULL;
        new_supplier_node->right = NULL;
        new_supplier_node->sum_of_sub_tree_left = 0;
        new_supplier_node->sum_of_sub_tree_right = 0;
        sup_Tree->root = insertsupToTree(sup_Tree->root, new_supplier_node);
        sup_Tree->elementCount++;
        return 0;
    }
    return -1;
}

Supplier_Node *insertsupToTree(Supplier_Node *root, Supplier_Node *new_node)
{
    if (root == NULL)
    {
        return new_node;
    }
    /* go right */
    if (root->sum_of_sub_tree_left > root->sum_of_sub_tree_right)
    {
        root->right = insertsupToTree(root->right, new_node);
        root->sum_of_sub_tree_right++;
    }
    else
    {
        /* go left */
        root->left = insertsupToTree(root->left, new_node);
        root->sum_of_sub_tree_left++;
    }
    return root;
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

int averageOfSupplierMoney(Suppliers_Tree *tree)
{
    if (tree)
        return (averageOfSupplierMoney_REC(tree->root) / tree->elementCount);
    return -1;
}

int averageOfSupplierMoney_REC(Supplier_Node *head)
{

    if (head == NULL)
    {
        return 0;
    }

    return head->supplier->sum_of_total_transactions_price + averageOfSupplierMoney_REC(head->left) + averageOfSupplierMoney_REC(head->right);
}

void print_sup(struct Supplier *sup)
{
    printf("Supplier name:\t%s\n", (sup)->name);
    printf("Supplier phone number:\t%s\n", (sup)->phone_number);
    printf("Supplier id :\t%s\n", (sup)->id);
    printf("supplier sum of transactions:\t%d\n", (sup)->sum_of_total_transactions_price);
    printf("number of transactions:\t%d\n\n", (sup)->count_transactions);
}

void print_sup_Tree(Supplier_Node *head)
{
    if (head == NULL)
    {
        return;
    }
    print_sup(head->supplier);
    print_sup_Tree(head->left);
    print_sup_Tree(head->right);
}

Supplier_Node *FindSupInTreeByid(Supplier_Node *head, char *sup_id)
{
    Supplier_Node *left = NULL, *right = NULL;
    if (head == NULL || strcmp(head->supplier->id, sup_id) == 0)
    {
        return head;
    }
    left = FindSupInTreeByid(head->left, sup_id);
    right = FindSupInTreeByid(head->right, sup_id);
    return left ? left : right;
    /*start with the root  if it`s not me go left and then go right*/
}

/* clone deep copy of tree */
Suppliers_Tree *tree_clone(Suppliers_Tree *tree)
{
    Suppliers_Tree *result = createSuppliersTree();
    result->root = rec_clone(tree->root);
    result->elementCount = tree->elementCount;
    return result;
}

Supplier_Node *rec_clone(Supplier_Node *head)
{
    Supplier_Node *clone = NULL;
    if (!head)
    {
        return NULL;
    }
    clone = clone_node(head);
    clone->left = rec_clone(head->left);
    clone->right = rec_clone(head->right);
    return clone;
}

Supplier_Node *clone_node(Supplier_Node *node)
{
    Supplier_Node *new_node = (Supplier_Node *)malloc(sizeof(Supplier_Node));
    new_node->supplier = (Supplier *)malloc(sizeof(Supplier));
    new_node->supplier->name = my_strdup(node->supplier->name);
    strcpy(new_node->supplier->id, node->supplier->id);
    strcpy(new_node->supplier->phone_number, node->supplier->phone_number);
    new_node->supplier->count_transactions = node->supplier->count_transactions;
    new_node->supplier->sum_of_total_transactions_price = node->supplier->sum_of_total_transactions_price;
    return new_node;
}

/* delete all Supplier */
int deleteAllSuppliers(Suppliers_Tree *Suppliers_Tree)
{
    if (Suppliers_Tree == NULL)
    {
        printf("list is empty\n");
        return -1;
    }
    if (Suppliers_Tree->root != NULL)
    {
        deleteAllSuppliers_REC(Suppliers_Tree->root);
        free(Suppliers_Tree);
    }
    return 0;
}

void deleteAllSuppliers_REC(Supplier_Node *head)
{
    if (head == NULL)
    {
        return;
    }
    deleteAllSuppliers_REC(head->left);
    deleteAllSuppliers_REC(head->right);
    free_Suppliers(head);
}

void free_Suppliers(Supplier_Node *sup)
{
    free(sup->supplier->name);
    free(sup);
}

/* 
int deleteSupplier(Suppliers_Tree * Suppliers_Tree , char *id) {

}
 */
