#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define INPUT_SIZE 1000000

void recursive_insertion_sort(int[], int);

int main(void){
	int arr[INPUT_SIZE];
	int i;
	for(i = 0; i < INPUT_SIZE; i++){
		arr[i] = random();
	}
	clock_t start_time = clock();
        recursive_insertion_sort(arr, INPUT_SIZE - 1);
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
** u is the index that points to tha item to be inserted in the sorted part
*/
void recursive_insertion_sort(int A[], int u){
	if(u > 1)
		recursive_insertion_sort(A, u - 1);
	int i = u - 1, key = A[u];
	while(i >= 0 && A[i] > key){
		A[i + 1] = A[i];
		i--;	
	}
	A[i + 1] = key;
}
