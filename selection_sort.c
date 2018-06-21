#include <stdio.h>

void selection_sort(int[], int);

int main(void){
	int arr[] = {10, 5, 3, 6, 7, 1, 9, 2};
	selection_sort(arr, sizeof(arr) / sizeof(arr[0]));
	int i, k;
	for(i = 0, k = sizeof(arr) / sizeof(arr[0]); i < k; i++){
		printf("%i ", arr[i]);
	}
	printf("\n");
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
