#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorting_algorithms.h"
#define INPUT_SIZE 100000

void selection_sort(int[], int);

int main(void){
	int arr[INPUT_SIZE];
	int i;
	for(i = 0; i < INPUT_SIZE; i++){
		arr[i] = random();
	}
	clock_t start_time = clock();	
        selection_sort(arr, INPUT_SIZE);
	clock_t end_time = clock();
	double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        /*for(i = 0; i < INPUT_SIZE; i++){
                printf("%i\n", arr[i]);
        }*/
	printf("\nExecution Time = %f\n", execution_time);
        return 0;
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
