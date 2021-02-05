/* Copyright (c) 2020, Dive into Systems, LLC (https://diveintosystems.org/)
 */

#include <stdio.h>

/* function prototypes: */
void printArray(int a[], int size);
void bubbleSort(int a[], int size);

/* prints out the contents of an array
 *  a: the array of int values
 *  size: the number of elements in the array
 */
void printArray(int a[], int size) {
    // An example of a function that doesn't return a value.
    int i;

    printf("Array Contents:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

/*  review bubble sorting from your java class and implement
 *  it for a C array, in which elements could be accessed through
 *  index notation just like Java arrays.
 *  Precondition:
 *  a: the array of int values
 *  size: the number of elements in the array
 *  returns: nothing
 *  Postcondition:
 *  a is sorted in ascending order 
 */
void bubbleSort(int a[], int size) {
    //TODO: write this function
}
