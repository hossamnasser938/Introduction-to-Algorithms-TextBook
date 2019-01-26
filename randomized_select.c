#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorting_algorithms.h"

#define INPUT_SIZE 1000000
#define ITH_ORDER_STATISTICS 33

int randomized_select ( int[], int, int, int );

int main() { 
    int A[INPUT_SIZE];
    int i;
    for ( i = 0; i < INPUT_SIZE; i++ ) {
	A[i] = random();
        //printf("%d\n", A[i]);
    }
    clock_t start_time = clock();
    printf( "%dth order statistics = %d\n", ITH_ORDER_STATISTICS, randomized_select( A, 0, INPUT_SIZE - 1, ITH_ORDER_STATISTICS ) );
    clock_t end_time = clock();
    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf( "Execution time = %f\n ", execution_time );
    return 0;
}

/*
** A is the array
** p start idex of current call
** r start idex of current call
** i refers to i-th order statistics(i-th smallest element) to be searched for
*/
int randomized_select ( int A[], int p, int r, int i ) {
    // if the array contains only one element, it is what we search for
    if ( p == r ) {
        return A[p];
    }
    // partition the array
    int q = randomized_partition( A, p, r );
    // after partitioning q is in its right place
    // if q has index equal to i then it is what we search for 
    if ( (i - 1) == q ) {
	return A[q];
    } // if not call randomized select recursively on the proper part according to the value of q with respect to i 
    else if ( (i - 1) < q ) {
	return randomized_select( A, p, q - 1, i );
    }
    else {
	return randomized_select( A, q + 1, r, i );
    }
}

