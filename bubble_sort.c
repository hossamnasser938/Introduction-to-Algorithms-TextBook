#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorting_algorithms.h"
#define INPUT_SIZE 100000

void bubble_sort(int[], int);
void swap(int[], int, int);

int main(void){
	int arr[INPUT_SIZE];
	int i;
	for(i = 0; i < INPUT_SIZE; i++){
		arr[i] = random();
	}
	clock_t start_time = clock();
        bubble_sort(arr, INPUT_SIZE);
	clock_t end_time = clock();
	double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;        
	/*for(i = 0; i < INPUT_SIZE; i++){
                printf("%i\n", arr[i]);
        }*/
	printf("\nExecution Time = %f\n", execution_time);        
	return 0;
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
