#include <stdio.h>

void insertion_sort(int[], int);

int main(void){
	int arr[] = {10, 5, 3, 6, 7, 1, 9, 2};
	insertion_sort(arr, sizeof(arr) / sizeof(arr[0]));
	int i, k;
	for(i = 0, k = sizeof(arr) / sizeof(arr[0]); i < k; i++){
		printf("%i ", arr[i]);
	}
	printf("\n");
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
