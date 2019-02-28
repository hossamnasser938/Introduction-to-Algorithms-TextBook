#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define true 1
#define false 0 
# define QUEUE_SIZE 10

struct queue {
    int head;
    int tail;
    int elements[QUEUE_SIZE];
};

struct queue* initialize_queue();
int isEmpty(struct queue*);
int isFull(struct queue*);
void enqueue(struct queue*, int);
int dequeue(struct queue*);
void print_queue(struct queue*);

int main() {
    struct queue* my_queue = initialize_queue();

    enqueue(my_queue, 5);
    enqueue(my_queue, 3);
    enqueue(my_queue, 3);
    enqueue(my_queue, 3);
    enqueue(my_queue, 3);
    dequeue(my_queue);
    dequeue(my_queue);
    dequeue(my_queue);
    enqueue(my_queue, 6);
    enqueue(my_queue, 6);
    enqueue(my_queue, 6);
    enqueue(my_queue, 6);
    enqueue(my_queue, 7);
    enqueue(my_queue, 7);

    print_queue(my_queue); 
    
    dequeue(my_queue);
    print_queue(my_queue);

    free(my_queue);
    return 0;
}

struct queue* initialize_queue() {
    struct queue* q = malloc(sizeof(struct queue));
    q->head = q->tail = 0;
}

int isEmpty(struct queue* q) {
    if (q->head == q->tail) {
	return true;
    }
    return false;
}

int isFull(struct queue* q) {
    if (q->head == (q->tail + 1) % QUEUE_SIZE) {
	return true;
    }
    return false;
}

void enqueue(struct queue* q, int e) {
    if (isFull(q)) {
	printf("overflow\n");
	return;
    }
    q->elements[q->tail] = e;
    q->tail = (q->tail + 1) % QUEUE_SIZE;
}

int dequeue(struct queue* q) {
    if (isEmpty(q)) {
	printf("underflow\n");
        return -INFINITY;
    }
    int x = q->elements[q->head];
    q->head = (q->head + 1) % QUEUE_SIZE;
    return x;
}

void print_queue(struct queue* q) {
    if (isEmpty(q)) {
	printf("Empty queue\n");
	return;
    }
    printf("Queue content:\n");
    int i = q->head;
    while ( true ) {
	printf("%d\n", q->elements[i]);
	if (i == q->tail - 1) {
	    return;
	}
    	i = (i + 1) % QUEUE_SIZE;
    }
}

