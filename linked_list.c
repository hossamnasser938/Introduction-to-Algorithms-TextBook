#include <stdio.h>
#include <stdlib.h>

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
void insert_node(struct list*, struct node*);
void delete_node(struct list*, struct node*); 
void print_list(struct list*);

int main() {
    struct list* l = create_list();
    struct node* n = create_node(5);
    l->head = n;
    
    for (int i = 0; i < 10; i++) {
	n = create_node(i);
	insert_node(l, n);
    }

    print_list(l);

    printf("Delete node of key = 4\n");
    n = search_list(l, 4);
    delete_node(l, n);
    print_list(l);
    return 0;
}

struct node* create_node(int k) {
    struct node* n = malloc(sizeof(struct node));
    n->key = k;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

struct list* create_list() {
    struct list* l = malloc(sizeof(struct list));
    l->head = NULL;
    l->tail = NULL;
}

struct node* search_list(struct list* l, int k) {
    struct node* temp = l->head;
    while(temp != NULL && temp->key != k) {
	temp = temp-> next;
    }
    return temp;
}

void insert_node(struct list* l, struct node* n) {
    if (l->head != NULL) {
        (l->head)->prev = n;
    }
    n->next = l->head;
    n->prev = NULL;
    l->head = n;    
}

void delete_node(struct list* l, struct node* n) {
    if (n->prev != NULL) {
	(n->prev)->next = n->next;
    }
    if (n->next != NULL) {
	(n->next)->prev = n->prev;
    }
    free(n);
}

void print_list(struct list* l) {
    if (l->head == NULL) {
	printf("Empty Linked list\n");
	return;
    }

    printf("Liked list content:\n");

    struct node* temp = l->head;
    printf("%d", temp->key);

    temp = temp->next;
    while (temp != NULL) {
	printf(" -> %d", temp->key);
	temp = temp->next;
    }
    
    printf("\n");
}



