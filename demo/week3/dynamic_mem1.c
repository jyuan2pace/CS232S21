#include <stdio.h>
#include <stdlib.h> //required for the memory functions
#include <stdbool.h>
#include <string.h>

int main()
{
    //We've been creating statically sized arrays like so:
    int data[] = {1, 2, 3};
    //This is permanently sized to 3.
    printf("data[1]=%d\n", data[1]);//accessing static array
    //Typically we want dynamically sized;

    int size;
    printf("How many elements do you want to store?: ");
    scanf("%d", &size); //ONLY USE WHAT WE NEED :) #StopGlobalWarming

    int * data2 = (int *)malloc(sizeof(int)*size);

    for(int i=0; i<size; i++) {
      data2[i] = i; //accessing a dyanamic arrays

      //a[i] -> *(a+i)
    }

       for(int i=0; i<size; i++) {
    printf("%d\n", data2[i]);//accessing static array

      //a[i] -> *(a+i)
    }

    free(data2);

} 