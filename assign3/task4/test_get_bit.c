#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
unsigned * get_bits(unsigned x,
					unsigned start,
					unsigned end);
/*
 * Tests that two arrays of size <size> are equal. Equal meaning that all the
 * elements in the arrays are equal.
 */
int array_equals(unsigned *arr1,
		unsigned *arr2,
		unsigned size) {

   int i;
   for (i = 0; i < size; i++) {
       if (arr1[i] != arr2[i]) {
           return 0;
       }
   }

   return 1;
}

/*
 * Prints an unsigned array as a bit string. This assumes that each integer
 * is only 0 or 1.
 */
void print_unsigned_array(unsigned *arr1,
		        unsigned size) {

    printf("0b");
    unsigned i;
    for (i = 0; i < size; i++) {
        printf("%u", arr1[i]);
    }
}

void test_get_bits(	unsigned x,
                  	unsigned s,
		  			unsigned e,
                  	unsigned * expected) {
    unsigned* a = get_bits(x, s, e);
    if(!array_equals(a, expected, e - s + 1)) {
        printf("get_bits(0x%08x,%u,%u): ",x,s,e);
		print_unsigned_array(a, e - s + 1);
		printf(", expected ");
		print_unsigned_array(expected, e - s + 1);
		printf("\n");
		assert(0);
    } else {
        printf("get_bits(0x%08x,%u,%u): ",x,s,e);
		print_unsigned_array(a, e - s + 1);
		printf(", correct\n");
    }
	//do not forget to free memory
    free(a);
}

int main(int argc,
         const char * argv[]) {
    printf("\nTesting get_bits()\n\n");
    unsigned expected;
    expected = 0;
    test_get_bits(0b1001110,0,0,&expected);
    expected = 1;
    test_get_bits(0b1001110,1,1,&expected);
    expected = 0;
    test_get_bits(0b1001110,5,5,&expected);
    expected = 1;
    test_get_bits(0b11011,3,3,&expected);
    expected = 0;
    test_get_bits(0b11011,2,2,&expected);
    expected = 0;
    test_get_bits(0b11011,9,9,&expected);

    unsigned expectedArr[] = {1,0,1,0};
    test_get_bits(0b111010101110, 3, 6, expectedArr);
    test_get_bits(0b01011111, 4, 7, expectedArr);
    test_get_bits(0b11110101, 0, 3, expectedArr);

    return 0;
}
