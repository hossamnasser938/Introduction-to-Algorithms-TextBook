#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define true 1
#define false 0 
# define STACK_SIZE 10

struct stack {
    int elements[STACK_SIZE];
    int top;  // stack pointer
};

struct stack* initialize_stack();
int isFull(struct stack*);
int isEmpty(struct stack*);
void push(struct stack*, int);
int pop(struct stack*);

void print_stack(struct stack*);

int main() {
    struct stack* my_stack = initialize_stack();

    push(my_stack, 5);
    push(my_stack, 10);
    push(my_stack, 3);
    print_stack(my_stack); 
    
    pop(my_stack);
    print_stack(my_stack);

    free(my_stack);
    return 0;
}

/**
** creates a stack structure, initialize its top, and return it
*/
struct stack* initialize_stack(){
    struct stack* s = malloc(sizeof(struct stack));
    s->top = -1;
    return s;
};

int isFull(struct stack* s) {
    if (s->top + 1 == STACK_SIZE){
	return true;
    } 
    return false;
}

int isEmpty(struct stack* s) {
    if (s->top == -1) {
	return true;
    }
    return false;
}

int pop(struct stack* s) {
    // check if the stack is empty
    if (isEmpty(s)) {
	printf("underflow\n");
	return -INFINITY;
    }
    // decrement top and return the item that was pointed to by the top before decrementing
    s->top--;
    return s->elements[s->top + 1];
}

void push(struct stack* s, int e) {
    // check if the stack is full
    if (isFull(s)) {
	printf("overflow\n");
	return;
    }
    // increment top and assign the item it now points to
    s->top++;
    s->elements[s->top] = e;    
}

void print_stack(struct stack* s) {
    if (isEmpty(s)) {
	printf("Empty stack\n");
	return;
    }
    printf("stack content:\n");
    for (int i = 0; i <= s->top; i++) {
	printf("%d\n", s->elements[i]);
    }
}
