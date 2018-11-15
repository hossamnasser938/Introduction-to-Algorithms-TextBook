#include <stdlib.h>
#include <math.h>
#include "sorting_algorithms.h"

struct Heap{
	int heap_size;
	int* array;
};

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
void max_heapify(struct Heap heap, int index){
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
		max_heapify(heap, largest);
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
		max_heapify(heap, i);
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
		max_heapify(heap, 1);
	}
}

/*
** A is the array with two sorted parts to be merged
** p is the index that points to the start of the first part
** q is the index that points to the end of the first part
** r is the index that points to the end of the second part
** the second part starts from index q + 1 
*/
void merge(int A[], int p, int q, int r){
	//calculating sizes of the two arrays needed to hold the items of the two parts
	int n1 = q - p + 1;
	int n2 = r - q;
	//declaring arrays
	int* L = (int*) malloc(n1 * sizeof(int));
	int* R = (int*) malloc(n2 * sizeof(int));
	//extracting the items of the two parts from the original array into two new arrays
	int i, j, k;
	for(i = 0; i < n1; i++){
		*(L + i) = A[p + i];
	}
	for(j = 0; j < n2; j++){
		*(R + j) = A[q + j + 1];
	}
	i = j = 0;        //clearing i and j to start merging
	//Merging
	for(k = p; k <= r; k++){
		if(i < n1 && j < n2){    //the two parts srill have items
			if(*(L + i) <= *(R + j)){
                        	A[k] = *(L + i);
                        	i++;
                	}
                	else{
                       		A[k] = *(R + j);
                       		j++;
                	}
		}
		else if(i >= n1){       //first part has run out of items
			while(j < n2){		
				A[k] = *(R + j);
				k++;
				j++;
			}
			free(L);
			free(R);
			return;
		}
		else{		//second part has run out of items
			while(i < n1){
				A[k] = *(L + i);
				k++;
				i++;
			}
			free(L);
			free(R);
			return;
		}	
	}
	free(L);
	free(R);
	return;
}

/*
** A is the array to be sorted using merge sort
** p is the index that points to the start of the portion of the array to be sorted
** r is the index that points to the end of the portion of the array to be sorted
*/
void merge_sort(int A[], int p, int r){
	if(p < r){
		int q = (p + r) / 2;
		merge_sort(A, p, q);
		merge_sort(A, q + 1, r);
		merge(A, p, q, r); 
	}
}

/*
** A is the array to be sorted using insertion sort
** n is the length of A
*/
void insertion_sort(int A[], int n){
	int key = 0, i, j;
	for(i = 1; i < n; i++){
		key = A[i];
		j = i - 1;
		while(j >= 0 && A[j] > key){
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = key;	
	}
	return;	
}

/*
** A is the array to be sorted using selection sort
** n is the length of A
*/
void selection_sort(int A[], int n){
	int j, i, min_index, temp;
	for(j = 0; j < n - 1; j++){
		min_index = j; 
		for(i = j + 1; i < n; i++){
			if(A[min_index] > A[i]){
				min_index = i;
			}
		}
		if(min_index != j){
			temp = A[j];
                	A[j] = A[min_index];
                	A[min_index] = temp;
		}
	}
	return;
}

/*
** A is the array to be sorted
** n is the number of items within A
*/
void bubble_sort(int A[], int n){
	int i, j, swapped_times;	
	for(i = 0; i < n - 1; i++){
		swapped_times = 0;
		for(j = n-1; j > 0; j--){
			if(A[j]	< A[j - 1]){
				swap(A, j, j - 1);
				swapped_times++;
			}	
		}
		if(swapped_times == 0)
			return;
	} 
}


