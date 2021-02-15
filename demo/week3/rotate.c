//in-class exericse
// rotate four integers by one position. Function rotate_4() takes four integer pointers as parameters and returns nothing. 
//%  ./rotate 1 2 3 4
//% 2 3 4 1


#include <stdio.h>
#include <stdlib.h>

void rotate_4(int *p_a, int*p_b, int*p_c, int* p_d) {
    //TO-DO: please implement left rotate 4 integers by one position
    int a[4];
    a[0] = *p_b;
    a[1] = *p_c;
    a[2] = *p_d;
    a[3] = *p_a;

    return a;


    int temp = *p_d;
    *p_d = *p_a;
    *p_a = *p_b;
    *p_b = *p_c;
    *p_c = temp;

    
}

int main(int argc, char ** argv) {
    //TO-DO check if there are 4 inputs.
    //print out an error message if there are not enough inputs.
    //hint: use argc
 
    if (argc != 5) {
      printf("Error! Not Enough Inputs! \n");
    }
    else {
      int a = atoi(argv[1]); //atoi converts string to int
      int b = atoi(argv[2]);
      int c = atoi(argv[3]);
      int d = atoi(argv[4]);
      rotate_4(&a, &b, &c, &d);
      printf("%d %d %d %d\n", a, b, c, d);
    }
    return 0;
}