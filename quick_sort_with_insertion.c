#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define INPUT_SIZE 1000000
#define MINIMUM_SIZE 100

void quick_sort(int[], int, int);
int partition(int[], int, int);
void insertion_sort(int[], int, int);
void swap(int[], int, int);

int main(void){
	int arr[INPUT_SIZE];
	int i;
	for(i = 0; i < INPUT_SIZE; i++){
		arr[i] = random();
	}
	clock_t start_time = clock();
        quick_sort(arr, 0, INPUT_SIZE - 1);
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
** p is the start index of the portion of A to be sorted in the current call
** r is the end index of the portion of A to be sorted in the current call   
*/
void quick_sort(int A[], int p, int r){
	if(r - p + 1 > MINIMUM_SIZE){
		int q = partition(A, p, r);
		quick_sort(A, p, q - 1);
		quick_sort(A, q + 1, r);
	}
	else
		insertion_sort(A, p, r);
}

/*
** A is the array with a portion to be partitioned
** p is the start index of the portion of A to be partitioned in the current call
** r is the end index of the portion of A to be partitioned in the current call
*/
int partition(int A[], int p, int r){
	int x = A[r];
	int i = p - 1;
	
	int j;	
	for(j = p; j < r ; j++){
		if(A[j] <= x){
			i++;
			swap(A, i, j);
		}
	}
	
	swap(A, i + 1, r);
	
	return i + 1;
}

/*
** A is the array with a portion to be sorted using insertion sort
** p is the start index of that portion
** r is the end index of that portion 
*/
void insertion_sort(int A[], int p, int r){
	int key = 0, i, j;
	for(i = p + 1; i <= r; i++){
		key = A[i];
		j = i - 1;
		while(j >= p && A[j] > key){
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = key;	
	}
	return;		
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
