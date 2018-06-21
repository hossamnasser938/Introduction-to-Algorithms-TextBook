#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorting_algorithms.h"
#define INPUT_SIZE 1000000

int binary_search(int[], int, int, int);

int main(void){
	int arr[INPUT_SIZE];
	int i;
	for(i = 0; i < INPUT_SIZE; i++){
		arr[i] = random();
	}
	clock_t start_time = clock();
        merge_sort(arr, 0, INPUT_SIZE - 1);        
	/*for(i = 0; i < INPUT_SIZE; i++){
                printf("%i\n", arr[i]);
        }*/
	int target = -1;
	if(binary_search(arr, target, 0, INPUT_SIZE - 1) == 1)
		printf("Target %i found\n", target);
	else
		 printf("Target %i not found\n", target);
	clock_t end_time = clock();
	double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("\nExecution Time = %f\n", execution_time);        
	return 0;
}

/*
** A is the previously_sorted array to be searched
** t is the target we search for
** s is the index that points to the start of the array
** e is the index that points to the end of the array
*/
int binary_search(int A[], int t, int s, int e)
{
	int found = 0;
	int mid = (s + e) / 2;
	if(mid > 0){
		if(A[mid] == t)
			return 1;
		else if(A[mid] > t)
			found = binary_search(A, t, s, mid - 1);
		else
			found = binary_search(A, t, mid + 1, e);
	}
	if(found == 1 || found == -1)
		return found;
	else{
		if(A[s] == t)
			return 1;
		else if(A[e] == t)
			return 1;
		else
			return -1;	
	}
}
