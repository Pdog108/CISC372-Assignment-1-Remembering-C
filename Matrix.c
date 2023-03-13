/*
    CISC372 Programming Assignment #1 -- Patrick Harris
*/
#include <stdio.h>
#include <stdlib.h>
#define N 5 
#define M 6 

/*
    Part 1:
        This function will construct a n x m 2d array in c implemented as an array of pointers,
        and one large contiguous block of memory to store the array elements.
        The array of pointers should be of type float* as well as the large array of type float
        should be dynamically allocated using malloc.
*/
void matrixArrayOfArrays(int n, int m) {
    //Part A: We need to allocate an array of pointers
    float** array = (float**) malloc(m* sizeof(float*));

    //initializes a 2d array of float values by allocating dynamic memory for each row
    for(int i = 0; i < m; i++) {
        array[i] = (float*) malloc(n * sizeof(float));
    }

    //Part B
    int num = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j <n; j++) {
            array[i][j] = num++;
        }
    }
    // Part C: Now we need to print out the array
    printf("Array:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.0f\t", array[i][j]);
        }
        printf("\n");
    }
    //Part D: Now we need to print out the transposed array (i.e. the first column then the second column etc.)
    printf("Transposed Array: \n");
    for(int i = 0; i < n;i++) {
        for(int j = 0; j < m; j++) {
            printf("%.0f\t", array[j][i]);
        }
        printf("\n");
    }

    //Part E: Now we need to deallocate all memory allocated with malloc so there are no memory leaks
    for(int i = 0; i < m; i++) {
        free(array[i]);
    }
    free(array);
}

/*
    Part 2:
        This function constructs an n x m 2d array in c implemented as an array of pointers, and one large contiguous block of memory to store the array elements. 
        The array of pointers of type float* as well as the large array of type float should be dynamically allocated using malloc.  
*/
void matrixOneBigArray( int n, int m) {
    //Part A: Allocate with malloc of size m* sizeof(float*) and second array of type float allocated as n * m * sizeof(float)
    int num = 0;
    float** array = (float**) malloc(m * sizeof(float*));
    float* arr = (float *) malloc((n*m)* sizeof(float));
    //Part B: Look through the array of pointers setting each pointer to the beginning of a row in the array (i.e. first pointer to the beginning of large array of floats, second pointer to the n+1 element of the array, etc.  
    for(int i = 0; i < m; i++){
        array[i] = &arr[i*n];
    }
    //Part C: Fill the array with the numbers 1-n*m so that he array is filled across the first row 1,2,3,4,n and the second row n+1,n+2,...,2n etc.
    for(int i = 0; i < m*n; i++){
        arr[i] = num++;
    }
        //Part D: Print the array out so that it looks like a matrix on the screen (you can use \t as a tab character in your printf statements to line things up nicely).
        for(int i= 0; i < m; i++){
            for(int j = 0; j < n; j++){
                printf("%f\t",array[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        //Part E: Print the array out transposed (i.e. first column then second column, etc.
        for(int i = 0; i < n; i++){
            for (int j = 0; j < m; j++) {
                printf("%f\t", array[j][i]);
            }
        printf("\n");
        }
    //Part F: Deallocate the mrmory allocated with malloc so that there are no memory leaks
    free (array);
    free(arr);
}
/*
    Main function that was provided
*/
int main(int argc,char** argv){ 
     matrixArrayOfArrays(N,M); 
     matrixOneBigArray(N,M); 
     return 0; 
}