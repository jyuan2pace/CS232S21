#include <stdio.h>
#include <stdlib.h> //required for the memory functions
#include <stdbool.h>
#include <string.h>

int main()
{
    //We've been creating statically sized arrays like so:
    int data[] = {1, 2, 3};
    //This is permanently sized to 3.
    printf("data[1]=%d\n", data[1]);
    //Typically we want dynamically sized;

    int size;
    printf("How many elements do you want to store?: ");
    scanf("%d", &size); //ONLY USE WHAT WE NEED :) #StopGlobalWarming

    printf("Enter each number followed by the enter key:\n");
    int *arr = malloc(size * sizeof (int));
    for (int i = 0; i < size; i++)
    {
        arr[i]=i;
    }

    printf("Your array:\n");
    for (int i = 0; i < size; i++)
    {
        printf("arr[%d] = %d\n",i, arr[i]);
    }
    
    //When done, make sure you call free! Otherwise memory leak
    free(arr);
} 