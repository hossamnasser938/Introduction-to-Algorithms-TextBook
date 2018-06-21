
#include <stdio.h>
#include <stdlib.h>

void merge_sort(int[], int, int);
void merge(int[], int, int, int);

int main(void){
	int arr[] = {10, 5, 3, 6, 7, 1, 9, 2};
        merge_sort(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);
        int i, k;
        for(i = 0, k = sizeof(arr) / sizeof(arr[0]); i < k; i++){
                printf("%i ", arr[i]);
        }
        printf("\n");
        return 0;
}

/*
** A is the array to be sorted using merge sort
** p is the index that points to the start of the portion of the array to be sorted
** r is the index that points to the end of the portion of the array to be sorted
*/
void merge_sort(int A[], int p, int r){
	if(p < r){
		int q = (p + r) / 2;
		merge_sort(A, p, q);
		merge_sort(A, q + 1, r);
		merge(A, p, q, r); 
	}
}

/*
** A is the array with two sorted parts to be merged
** p is the index that points to the start of the first part
** q is the index that points to the end of the first part
** r is the index that points to the end of the second part
** the second part starts from index q + 1 
*/
void merge(int A[], int p, int q, int r){
	//calculating sizes of the two arrays needed to hold the items of the two parts
	int n1 = q - p + 1;
	int n2 = r - q;
	//declaring arrays
	int* L = (int*) malloc(n1 * sizeof(int));
	int* R = (int*) malloc(n2 * sizeof(int));
	//extracting the items of the two parts from the original array into two new arrays
	int i, j, k;
	for(i = 0; i < n1; i++){
		*(L + i) = A[p + i];
	}
	for(j = 0; j < n2; j++){
		*(R + j) = A[q + j + 1];
	}
	i = j = 0;        //clearing i and j to start merging
	//Merging
	for(k = p; k <= r; k++){
		if(i < n1 && j < n2){    //the two parts srill have items
			if(*(L + i) <= *(R + j)){
                        	A[k] = *(L + i);
                        	i++;
                	}
                	else{
                       		A[k] = *(R + j);
                       		j++;
                	}
		}
		else if(i >= n1){       //first part has run out of items
			while(j < n2){		
				A[k] = *(R + j);
				k++;
				j++;
			}
			free(L);
			free(R);
			return;
		}
		else{		//second part has run out of items
			while(i < n1){
				A[k] = *(L + i);
				k++;
				i++;
			}
			free(L);
			free(R);
			return;
		}	
	}
	free(L);
	free(R);
	return;
}
