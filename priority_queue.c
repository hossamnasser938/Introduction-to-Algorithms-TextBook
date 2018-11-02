#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define true 1
#define false 0

struct Heap{
	int heap_size;
	int* array;
};

int parent(int);
int left(int);
int right(int);
void max_hearify(struct Heap, int);
void swap(int[], int, int);
int heap_maximum(struct Heap);
int heap_extract_maximum(struct Heap);
int heap_increase_key(struct Heap*, int, int);
void heap_insert(struct Heap*, int);

int main(){
	int arr[10];

	struct Heap heap;
	heap.array = arr;
	heap.heap_size = 0; 

	int i, key;	
	for(i = 0; i < 10 ; i++){
		key = random();
		heap_insert(&heap, key);
		printf("element %i with priority %i \n", i + 1, key);
	}

	int max = heap_extract_maximum(heap);
	printf("maximum priority %i \n", max);
}

/*
** index is the index of a node
** returns the nodes's parent index 
*/
int parent(int index){
	return index / 2;
}

/*
** index is the index of a node
** returns the nodes's left child index 
*/
int left(int index){
	return 2 * index;
}

/*
** index is the index of a node
** returns the nodes's right child index 
*/
int right(int index){
	return 2 * index + 1;
}

/*
** heap is an object of heap structure
** index is the index of a node
** given a node that has a left and right child each represents a max-heap and their parent needs to be put in its right position so the whole subtree represents a max-heap
*/
void max_hearify(struct Heap heap, int index){
	int r = right(index);
	int l = left(index);
	int largest;
	
	if(l <= heap.heap_size && heap.array[l] > heap.array[index]){
		largest = l;
	}
	else{
		largest = index;
	}
	
	if(r <= heap.heap_size && heap.array[r] > heap.array[largest]){
		largest = r;
	}	

	if(index != largest){
		swap(heap.array, index, largest);
		max_hearify(heap, largest);
	}
}

/*
** A is the array that holds items to be swapped
** i is the index of the item to be swapped
** j is the index of the other item to be swapped
*/
void swap(int A[], int i, int j){
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

/*
** returns the element with maximum priority
*/
int heap_maximum(struct Heap heap){
	return heap.array[0];
}

/*
** returns the element with maximum priority and remove it from the queue
*/
int heap_extract_maximum(struct Heap heap){	
	if(heap.heap_size < 1)
		return -1;	//error
		
	int max = heap.array[0];
	heap.array[0] = heap.array[heap.heap_size - 1]; 
	heap.heap_size--;
	max_hearify(heap, 0);
	return max;
}

/*
** increases the prioprity of a given element
*/
int heap_increase_key(struct Heap* heap, int index, int key){
	if(key <= heap->array[index])
		return false;	//error

	heap->array[index] = key;
	while(index > 0 && heap->array[parent(index)] < heap->array[index]){
		swap(heap->array, parent(index), index);
		index = parent(index);
	}
	return true;
}

/*
** inserts a new item in the priority queue
*/
void heap_insert(struct Heap* heap, int key){
	heap->heap_size++;
	heap->array[heap->heap_size - 1] = (int)(-INFINITY);
	heap_increase_key(heap, heap->heap_size - 1, key);
}

