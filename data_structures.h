#ifndef SORTING_ALGORITHMS_
#define SORTING_ALGORITHMS_

struct node {
    int key;
    struct node* next;
    struct node* prev;
};

struct list {
    struct node* head;
    struct node* tail;
};

struct node* create_node(int);
struct list* create_list();
struct node* search_list(struct list*, int);
void insert_node(struct list**, struct node*);
void delete_node(struct list*, struct node*); 
void print_list(struct list*);

#endif
