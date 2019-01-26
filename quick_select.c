#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorting_algorithms.h" 

#define INPUT_SIZE 1000000
#define ITH_ORDER_STATISTICS 33

int find_group_median ( int[], int, int );
int find_median ( int[], int );
int special_partition(int[], int, int, int );
int select_ith( int[], int, int, int );

int main() {
    int A[INPUT_SIZE];
    int i;
    for ( i = 0; i < INPUT_SIZE; i++ ) {
	A[i] = random();
        //printf("%d\n", A[i]);
    }
    clock_t start_time = clock();
    printf( "%dth order statistics = %d\n", ITH_ORDER_STATISTICS, select_ith( A, 0, INPUT_SIZE - 1, ITH_ORDER_STATISTICS ) );
    clock_t end_time = clock();
    double execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf( "Execution time = %f\n ", execution_time );
    return 0;
}

int find_group_median (int A[], int p, int r) {
    insertion_sort_helper(A, p, r);
    return A[(r - p) / 2 + p];
}

int find_median ( int A[], int n ) {
    if( n <= 5 ) {
	return find_group_median( A, 0, n - 1 );
    }
    // determine the number of groups
    int medians_count;
    if ( n % 5 == 0 ) {
	medians_count = n / 5;
    } 
    else {
	medians_count = n / 5 + 1;
    }

    int medians[medians_count];    

    // determine the median for each group
    int i;
    for ( i = 0; i < (n - 4); i += 5 ) {
        medians[i / 5] = find_group_median( A, i, i + 4 );
    }

    if ( n % 5 != 0 ) {
	medians[medians_count - 1] = find_group_median( A, i, n - 1 ); 
    }

    // determine the median of medians
    return find_median( medians, medians_count );    
}

/*
** partition on a given pivot
*/
int special_partition(int A[], int p, int r, int median){
    int i;
    for ( i = p; i <= r; i++ ) {
	if( A[i] == median ) {
	    swap( A, i, r );
	    break;
 	}
    }
    return partition( A, p, r );
}

int select_ith( int A[], int p, int r, int i ) {
    int median = find_median( A, r - p + 1 );
    int q = special_partition( A, p, r, median );
    if ( (i - 1) == q ) {
	return A[q];
    }
    else if ( (i - 1) < q ) {
	return select_ith(A, p, q - 1, i);
    }
    else {
	return select_ith(A, q + 1, r, i);
    }
}
