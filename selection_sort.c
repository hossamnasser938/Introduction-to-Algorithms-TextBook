#include <stdio.h>
#include <stdlib.h>
#define INPUT_SIZE 10

void selection_sort(int[], int);

int main(void){
	int arr[INPUT_SIZE];
	int i;
	for(i = 0; i < INPUT_SIZE; i++){
		arr[i] = random();
	}
        selection_sort(arr, INPUT_SIZE);
        int k;
        for(i = 0; i < INPUT_SIZE; i++){
                printf("%i\n", arr[i]);
        }
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
