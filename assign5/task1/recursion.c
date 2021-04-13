#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* both of these routines print and sum up numbers i where start <= i < stop */

long
printSumRangeIterative(int start, int stop)
{
    int i;
    long sum = 0;
    for(i = start; i < stop; i++) {
        printf("%d\n", i);
	sum += i;
    }
    return sum;
}

long
printSumRangeRecursive(int start, int stop)
{
    long sum=0;
    if(start < stop) {
        printf("%d\n", start);
        sum=start+printSumRangeRecursive(start+1, stop);

    }
    return sum;
}


int
main(int argc, char **argv)
{

    if(argc != 2) {
        fprintf(stderr, "Usage: %s an-integer\n", argv[0]);
        return 1;
    }
    int input = atoi(argv[1]);
    printf("printSumRangeIterative(0, %d)\n", input);
    printf("sum=%ld\n", printSumRangeIterative(0, input));
    printf("printSumRangeRecursive(0, %d)\n", input);
    printf("sum=%ld\n", printSumRangeRecursive(0, input));
    return 0;
}
