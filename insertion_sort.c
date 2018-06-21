#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define INPUT_SIZE 100000

void insertion_sort(int[], int);

int main(void){
	int arr[INPUT_SIZE];
	int i;
	for(i = 0; i < INPUT_SIZE; i++){
		arr[i] = random();
	}
	clock_t start_time = clock();
        insertion_sort(arr, INPUT_SIZE);
	clock_t end_time = clock();
	double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
        /*for(i = 0; i < INPUT_SIZE; i++){
                printf("%i\n", arr[i]);
        }*/
	printf("\nExecution Time = %f\n", execution_time);
        return 0;
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
