#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define INPUT_SIZE 1000000

int minimum( int[], int );
int maximum( int[], int );
int* min_max_normal( int[], int );
int* min_max_better( int[], int );
int* min_max_enhanced( int[], int );

int main() {
    int A[INPUT_SIZE];
    
    // Generate an array of random numbers
    int i;
    for ( i = 0; i < INPUT_SIZE; i++ ) {
	A[i] = random();
	// printf( "%d\n", A[i] );
    }
     
    // Determine and print maximum and minimum independently
    printf( "Minimum value = %d\n", minimum(A, INPUT_SIZE) );
    printf( "Maximum value = %d\n", maximum(A, INPUT_SIZE) );
    
    // Determine and print both maximum and minimum using the normal way(number of comparisons 2n - 2) 
    clock_t start_time = clock();
    int* normal_min_max = min_max_normal(A, INPUT_SIZE);
    clock_t end_time = clock();
    double execution_time = (double) ( end_time - start_time ) / CLOCKS_PER_SEC;

    // print normal way result and execution time
    printf( "normal_min_max = [%d %d]\n", *(normal_min_max), *(normal_min_max + 1) );
    printf( "normal execution time = %f\n", execution_time );

    // Determine and print both maximum and minimum using the enhanced way(number of comparisons (3n / 2) - 2)
    start_time = clock();
    int* enhanced_min_max = min_max_enhanced(A, INPUT_SIZE); 
    end_time = clock();
    execution_time = (double) ( end_time - start_time ) / CLOCKS_PER_SEC;

    // print normal way result and execution time
    printf( "enhanced_min_max = [%d %d]\n", *(enhanced_min_max), *(enhanced_min_max + 1) );
    printf( "enhanced execution time = %f\n", execution_time );
    return 0;
}

int minimum( int A[], int n ) {
    // Assume the first element is the minmum
    int min = A[0];
    // Compare that element with every element to get the minimum of them
    int i;
    for ( i = 1; i < n; i++ ) {
	if ( min > A[i] ) {
	    min = A[i]; 
        }
    }
    return min;
}

int maximum( int A[], int n ) {
    int max = A[0];
    int i;
    for ( i = 1; i < n; i++ ) {
	if ( max < A[i] ) {
	    max = A[i]; 
        }
    }
    return max;
}

int* min_max_normal( int A[], int n ) {
    int* min_max = malloc( 2 * sizeof(int) );
    
    int min = minimum( A, n );
    int max = maximum( A, n );

    *(min_max) = min;
    *(min_max + 1) = max;    
    return min_max;
}

int* min_max_better( int A[], int n ) {
    // Reserve space for an array of two elements(max and min) to be returned
    int* min_max = malloc( 2 * sizeof(int) );
    int min, max;
    
    // Initialize min and max with first two elemenrsts
    if( A[0] < A[1] ) {
        min = A[0];
        max = A[1];    
    } 
    else {
        min = A[1];
	max = A[0];
    }
    
    // Iterate through the rest of the elements 
    int i;
    for ( i = 2; i < n; i++ ) {
	// if the current element is less than the minimum no need to compare it with the maximum 
        if ( min > A[i] ) {
	    min = A[i];
	}
	else {
            // If it is larger than the minimum compare it with the maximum
	    if ( max < A[i] ) {
		max = A[i];
	    }
	}
    }

    *(min_max) = min;
    *(min_max + 1) = max;    
    return min_max;
}

int* min_max_enhanced( int A[], int n ) {
    int* min_max = malloc( 2 * sizeof(int) );
    int min, max;

    int i;
    if (n % 2 == 0) { // even number of elements
        // Assign max and min properly
        i = 2;
	if( A[0] < A[1] ) {
            min = A[0];
            max = A[1];    
        } 
        else { // odd number f elements
            min = A[1];
	    max = A[0];
        }
    }
    else {
	i = 1;
        min = max = A[0];
    }

    int temp_min, temp_max;
    // iterate through pairs of elements
    for ( i; i < n; i += 2 ) {
	// (3 comparisons for each pair instead of 4)
        // determine max and min of the pairs elements	
	if( A[i] < A[i + 1] ) {
	    temp_min = A[i];
	    temp_max = A[i + 1];	
	}
        // compare the pairs with min and max 
	else {
	    temp_min = A[i + 1];
	    temp_max = A[i];
	}

	if ( min > temp_min ) {
	    min = temp_min;
	}
	if( max < temp_max ) {
	    max = temp_max;
	}
    }

    *(min_max) = min;
    *(min_max + 1) = max;    
    return min_max;
}

