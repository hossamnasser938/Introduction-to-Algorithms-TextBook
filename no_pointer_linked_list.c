#include <stdio.h>
#include <stdlib.h>

#define LIST_SIZE 10

int key[LIST_SIZE];
int next[LIST_SIZE];
int prev[LIST_SIZE];
int head;
int _free;

void initialize_list();
int allocate_object();
int free_object(int);
void insert(int);
void print_list(); 

int main() {
    initialize_list();
    
    for (int i = 0; i < 15; i++) {
	insert(i * 10);
    }

    print_list();
    
    return 0;
}

void initialize_list() {
    head = -1;
    _free = 0;
    for (int i = _free; i < LIST_SIZE - 1; i++) {
	next[i] = i + 1;
    }
    next[LIST_SIZE - 1] = -1;
}

int allocate_object() {
    if (_free == -1) {
	printf("Overflow\n");
	return -1;
    }
    int x = _free;
    _free = next[_free];
    return x;
}

int free_object(int x) {
    next[x] = _free;
    _free = x;
}

void insert(int k) {
    int x = allocate_object();
    if (x == -1) {
	return;
    }
    key[x] = k;
    prev[x] = -1;
    if (head == -1) {
        head = x;
        next[x] = -1;
    }
    else {
        next[x] = head;
        head = x;
    }
}

void print_list() {
    if (head == -1) {
	printf("Empty List\n");
    }
    printf("List content:\n");
    int temp = head;
    while (temp != -1) {
	printf("%d\n", key[temp]);
	temp = next[temp];
    }
}



