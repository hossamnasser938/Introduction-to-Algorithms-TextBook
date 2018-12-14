#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define INPUT_SIZE 1000000
#define MAXIMUM 1000

int * counting_sort(int[], int, int);

int main(){
    int *arr = malloc(INPUT_SIZE * sizeof(int));
    int i;
    for(i = 0; i < INPUT_SIZE; i++){
	arr[i] = random() % MAXIMUM;
    }
    clock_t start_time = clock();
    int* sorted = counting_sort(arr, INPUT_SIZE, MAXIMUM);
    clock_t end_time = clock();
    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    /*for(i = 0; i < INPUT_SIZE; i++){
          printf("%i\n", sorted[i]);
    }*/
    printf("\nExecution Time = %f\n", execution_time);
    free(arr);
    return 0;
}

int * counting_sort(int A[], int n, int k){
    //Declare the auxilliary array C
    int C[k];

    //Declare the array to hold sorted items
    int *B = malloc(n * sizeof(int));

    //Initialize C with zeros
    int i;
    for(i = 0; i < k; i++){
	C[i] = 0;
    }

    //Fill C with number of repititions for each unique element in A
    for(i = 0; i < n; i++){
	C[A[i]] = C[A[i]] + 1;
    }

    //Alter C to have for each elemnt in A the number of elements less than it
    for(i = 1; i < k; i++){
	C[i] = C[i] + C[i - 1];
    }

    //Put elements from A into their correct position in B
    for(i = n - 1; i >= 0; i--){
	*(B + C[A[i]]) = A[i];
	C[A[i]] = C[A[i]] - 1; 
    }
    
    //Return the sorted array B
    return B;
} 
