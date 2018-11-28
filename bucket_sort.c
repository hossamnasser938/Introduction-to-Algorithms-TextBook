#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define INPUT_SIZE 100000

/*
** the node of the linked list
*/
struct node{
    struct node* next;
    struct node* previous;
    double value;
};

struct node* insert_new_node(struct node*, double);
void insertion_sort(struct node*);
int concatenate(double[], struct node*, int);
void bucket_sort(double[], int);


int main(){
    double array[INPUT_SIZE];
    int i;
    for(i = 0; i < INPUT_SIZE; i++){
	array[i] = (double)rand() / (double)RAND_MAX;
    }
    clock_t start_time = clock();
    bucket_sort(array, INPUT_SIZE);
    clock_t end_time = clock();
    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    /*for(i = 0; i < INPUT_SIZE; i++){
        printf("%f\n", array[i]);
    }*/
    printf("\nExecution Time = %f\n", execution_time);
    return 0;
}

/*
** inserts a bew node int a linked list
** root is the root node of the linked list
** val is the value to be inserted
*/
struct node* insert_new_node(struct node* root, double val){
    //Make room for the new node
    struct node* new = (struct node*) malloc(sizeof(struct node));
    new->value = val;
    //Insert the node at the beginning of the list
    if(root == NULL){
	root = new;
    }
    else{
	new->next = root;
        root->previous = new;
        root = new;
    }
    return root;
}

/*
** sorts a linked list
** root is the root node of the linked list
*/
void insertion_sort(struct node* root){
    //Check if the list is empty or has only one node
    if(root == NULL || root->next == NULL)
	return;

    //Start from the second node
    struct node* i = root->next;
    struct node* j;
    double key;
    while(i != NULL){
	key = i->value;
	j = i->previous;
        while(j != NULL && (j->value) > key){
	    (j->next)->value = j->value;
	    j = j->previous;
	}
	if(j == NULL){
	    root->value = key;
	}
	else{
	    (j->next)->value = key;
	}
        i = i->next; 
    }
}

/*
** concatenate a linked list items in the array
** root is the root node of the linjed list to be concatenated
** start_index is the index in the array to start adding linked list's items
*/
int concatenate(double A[], struct node* root, int start_index){
    struct node* i = root;
    int j = start_index;
    while(i != NULL){
	A[j] = i->value;
	i = i->next;	
	j++;
    }
    return j;
}

/*
** sort using bucket sort
*/
void bucket_sort(double A[], int n){
    //Declare the array of linked lists
    struct node* B[n];
    int i;
    for(i = 0; i < n; i++){
	B[i] = NULL;
    }
    
    //Insert each element of A into its correct linked list
    for(i = 0; i < n; i++){
	B[(int)(n * A[i])] = insert_new_node(B[(int)(n * A[i])], A[i]);
    }

    //Sort all linked lists using insertion sort
    for(i = 0; i < n; i++){
	insertion_sort(B[i]);
    }

    //Concatenate all linked lists into one list
    int index = 0;
    for(i = 0; i < n; i++){
	index = concatenate(A, B[i], index);
    }
}






