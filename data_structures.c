#include <stdio.h>
#include <stdlib.h>
#include "data_structures.h"

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
	if ( l == NULL ) {
		return NULL;
	}
	print_list(l);
	
    struct node* temp = l->head;	
	
    while(temp != NULL && k != temp->key ) {
		printf("temp->key %d\n", temp->key);
		temp = temp-> next;
    }

    return temp;
}

void insert_node(struct list** l, struct node* n) {
	if ( *l == NULL ) {
		*l = create_list();
	}

    if ((*l)->head != NULL) {
        ((*l)->head)->prev = n;
    }
    n->next = (*l)->head;
    n->prev = NULL;
    (*l)->head = n;    
}

void delete_node(struct list* l, struct node* n) {
	if ( l == NULL ) {
		printf("no list to delete from\n");
	}

    if (n->prev != NULL) {
	(n->prev)->next = n->next;
    }
    if (n->next != NULL) {
	(n->next)->prev = n->prev;
    }
    free(n);
}

void print_list(struct list* l) {
	if (l == NULL) {
		printf("list to print is NULL \n");
		return;
	}
	    
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
