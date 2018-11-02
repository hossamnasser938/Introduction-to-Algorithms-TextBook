#include <stdlib.h>
#include "sorting_algorithms.h"

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

/*
** A is the array to be sorted
** n is the number of items within A
*/
void bubble_sort(int A[], int n){
	int i, j, swapped_times;	
	for(i = 0; i < n - 1; i++){
		swapped_times = 0;
		for(j = n-1; j > 0; j--){
			if(A[j]	< A[j - 1]){
				swap(A, j, j - 1);
				swapped_times++;
			}	
		}
		if(swapped_times == 0)
			return;
	} 
}

