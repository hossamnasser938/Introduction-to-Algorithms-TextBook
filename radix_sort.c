#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define INPUT_SIZE 1000000
#define BASE 10

int calc_max(int[], int);
void count_sort(int[], int, int);
void radix_sort(int[], int);

int main(){
    int arr[INPUT_SIZE];
    int i;
    for(i = 0; i < INPUT_SIZE; i++){
	arr[i] = random();
    }
    clock_t start_time = clock();
    radix_sort(arr, INPUT_SIZE);
    clock_t end_time = clock();
    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;        
    /*for(i = 0; i < INPUT_SIZE; i++){
          printf("%i\n", arr[i]);
    }*/
    printf("\nExecution Time = %f\n", execution_time);        
    return 0;
}

/*
** calculate the maximum element in the array
*/
int calc_max(int A[], int n){
    int max = A[0];
    int i;
    for(i = 1; i < n; i++){
	if(A[i] > max)
	    max = A[i];
    }
    return max;
}

/*
** use count sort to sort from rigtmost bit to leftmost bit
*/
void count_sort(int A[], int n, int exp){
    int output[n], aux[BASE];

    //Initialize auxiliary array
    int i;
    for(i = 0; i < BASE; i++){
	aux[i] = 0; 
    }
	
    //Fill auxiliary array with the number of repetitions for each element in A
    for(i = 0; i < n; i++){
	aux[(A[i] / exp) % BASE]++; 
    }

    //Modify auxiliary to have the number of elements less than each element in A
    for(i = 1; i < BASE; i++){
	aux[i] = aux[i] + aux[i - 1];
    }

    //Put each element from A into its correct position in output
    for(i = n - 1; i >= 0; i--){
	 output[aux[(A[i] / exp) % BASE] - 1] = A[i];
         aux[(A[i] / exp) % BASE]--;
    }

    //Copy array output to array A
    for(i = 0; i < n; i++){
	A[i] = output[i];
    }    
}

/*
** radix sort with count sort as a subroutine as it is a stable algorithm
*/
void radix_sort(int A[], int n){
    //Calcuate the maximum number in the array
    int max = calc_max(A, n);

    int i;
    for(i = 1; max / i > 0; i *= BASE){
	count_sort(A, n, i);
    }
}
