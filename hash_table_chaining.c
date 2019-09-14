#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "data_structures.h"
#define HASH_TABLE_SIZE 1000

struct hash_table {
	struct list* array[HASH_TABLE_SIZE];
};

struct hash_table* initialize_hash_table();
int hash(int);
void insert(struct hash_table*, struct node*);
struct node* search(struct hash_table*, int);
void delete(struct hash_table*, struct node*);

int main() {
	struct hash_table* T = initialize_hash_table();
	
	for (int i = 0; i < HASH_TABLE_SIZE * 3; i++) {
		int x = (int)(((double) rand() / (RAND_MAX)) * 1000000);
		printf("x = %d\n", x);
		struct node* n = create_node(x);

		insert(T, n);
	}	

	int input;
	printf("search for: ");
	scanf("%d", &input);	

	struct node* n = search(T, input);

	if ( n == NULL ) {
		printf("%d not found\n", input);
	}
	else {
		printf("%d found\n", input);
	}

	return 0;
}

struct hash_table* initialize_hash_table() {
	struct hash_table* t = malloc(sizeof(struct hash_table));

	for (int i = 0; i < HASH_TABLE_SIZE; i++) {
		t->array[i] = NULL;
	}

	return t; 
}

int hash(int key) {
	return key % HASH_TABLE_SIZE;
}

void insert(struct hash_table* T, struct node* n) {
	int h = hash(n->key);
	printf("%d hashed to %d\n", n->key, h);
	insert_node(&(T->array[h]), n);
}

struct node* search(struct hash_table* T, int key) {
	int h = hash(key);

	return search_list(T->array[h], key);
}

void delete(struct hash_table* T, struct node* n) {
	int h = hash(n->key);
	delete_node(T->array[h], n);
}
