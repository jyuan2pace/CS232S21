#include <stdio.h>
#include <stdlib.h>

int midpoint_original(int x, int y) {
    return (x + y)/2;
}
int midpoint_A(int x, int y) {
    return x + ((y - x) / 2);
}

int midpoint_B(int x, int y) {
    return ((unsigned int)x + (unsigned int)y) >> 1;
}

int midpoint_C(int x, int y) {
    return (x & y) + ((x ^ y) >> 1);
}

int main(int argc, char ** argv) {
    int a = atoi(argv[1]); //atoi converts string to int
    int b = atoi(argv[2]);
    printf("midpoint_original = %d\n", midpoint_original(a, b));
    printf("midpoint_A = %d\n", midpoint_A(a, b));
    printf("midpoint_B = %d\n", midpoint_B(a, b));    
    printf("midpoint_C = %d\n", midpoint_C(a, b));
    return 0;
}
