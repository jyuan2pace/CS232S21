#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
void set_bits(unsigned * x,
             unsigned start,
             unsigned end,
             unsigned *v);

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
void print_unsigned_array(	unsigned *arr1,
		        			unsigned size) {

    printf("0b");
    unsigned i;
    for (i = 0; i < size; i++) {
        printf("%u", arr1[i]);
    }
}

void test_set_bits(	unsigned x,
                  	unsigned s,
		  			unsigned e,
                  	unsigned * v,
                  	unsigned expected) {
    unsigned o = x;
    set_bits(&x, s, e, v);
    if(x!=expected) {
        printf("set_bits(0x%08x,%u,%u,",o,s,e);
		print_unsigned_array(v, e - s + 1);
		printf("): 0x%08x, expected 0x%08x\n",x,expected);
		assert(0);
    } else {
        printf("set_bits(0x%08x,%u,%u,%u): 0x%08x, correct\n",o,s,e,*v,x);
    }
}

int main(int argc,
         const char * argv[]) {
	unsigned expectedArr[] = {1,0,1,0};
    printf("\nTesting set_bits()\n\n");
    test_set_bits(0b1001110,2,2,&expectedArr[1],0b1001010);
    test_set_bits(0b1101101,0,0,&expectedArr[1],0b1101100);
    test_set_bits(0b1001110,2,2,expectedArr,0b1001110);
    test_set_bits(0b1101101,0,0,expectedArr,0b1101101);
    test_set_bits(0b1001110,9,9,&expectedArr[1],0b1001110);
    test_set_bits(0b1101101,4,4,&expectedArr[1],0b1101101);
    test_set_bits(0b1001110,9,9,expectedArr,0b1001001110);
    test_set_bits(0b1101101,7,7,expectedArr,0b11101101);

    test_set_bits(0b111111,0,3,expectedArr,0b110101);
    test_set_bits(0b111111,2,5,expectedArr,0b010111);
    test_set_bits(0b111111,1,4,expectedArr,0b101011);

    test_set_bits(0,0,3,expectedArr,0b0101);
    test_set_bits(0,2,5,expectedArr,0b010100);
    test_set_bits(0,1,4,expectedArr,0b01010);

    printf("\n");
    return 0;
}
