#include <stdio.h>
#include <stdlib.h>
#define INPUT_SIZE 10

void insertion_sort(int[], int);

int main(void){
	int arr[INPUT_SIZE];
	int i;
	for(i = 0; i < INPUT_SIZE; i++){
		arr[i] = random();
	}
        insertion_sort(arr, sizeof(arr) / sizeof(arr[0]));
        int k;
        for(i = 0, k = sizeof(arr) / sizeof(arr[0]); i < k; i++){
                printf("%i\n", arr[i]);
        }
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
