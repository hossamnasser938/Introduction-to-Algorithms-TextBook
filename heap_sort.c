#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define INPUT_SIZE 100000

struct Heap{
	int heap_size;
	int* array;
};

int left(int);
int right(int);
void max_hearify(struct Heap, int);
struct Heap build_max_heap(int[], int);
void heap_sort(int[], int);
void swap(int[], int, int);

int main(void){
	int arr[INPUT_SIZE];
	int i;
	for(i = 0; i < INPUT_SIZE; i++){
		arr[i] = random();
	}
	clock_t start_time = clock();
        heap_sort(arr, INPUT_SIZE);
	clock_t end_time = clock();
	double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;        
	/*for(i = 0; i < INPUT_SIZE; i++){
                printf("%i\n", arr[i]);
        }*/
	printf("\nExecution Time = %f\n", execution_time);        
	return 0;
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
** array is an array to be converted into a max-heap
** n is the length of the array
** return a max-heap
*/
struct Heap build_max_heap(int array[], int n){
	struct Heap heap;
	heap.heap_size = n;
	heap.array = array;
	
	int i;	
	for(i = heap.heap_size / 2 - 1; i >= 0; i--){
		max_hearify(heap, i);
	}

	return heap; 
}

/*
** array is an array to be ordered using a heap_sort
** n is the length of the array
*/
void heap_sort(int array[], int n){
	struct Heap heap = build_max_heap(array, n);
	
	int i;
	for(i = n - 1; i > 0; i--){
		swap(heap.array, 1, i);
		heap.heap_size --;
		max_hearify(heap, 1);
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
