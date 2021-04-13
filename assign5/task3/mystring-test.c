#include <stdio.h>
#include <stdlib.h>

#include "mystring.h"

int main(int argc, char **argv) {
	mystring_t *s;
	
	printf("Calling mystring_new()\n");
	s = mystring_new();
	
	printf("Calling mystring_delete()\n");
	mystring_delete(s);
	
	printf("mystring_new() again\n");
	s = mystring_new();

	printf("These should all return space (mystring_get()): ");
	printf("%c ", mystring_get(s, 0));
	printf("%c ", mystring_get(s, 1));
	printf("%c\n", mystring_get(s, 2));

	printf("Doing a bunch of mystring_set()s\n");
	mystring_set(s, 0, 'h');
	mystring_set(s, 11, 'a');
	mystring_set(s, 15, 'z');
	mystring_set(s, 24, 'm');
    	mystring_set(s, 500, 's');
	mystring_set(s, 12, 'b');
	mystring_set(s, 25, '!');

	printf("These should be equal:\n");
	printf("h = %c\n", mystring_get(s, 0));
	printf("a = %c\n", mystring_get(s, 11));
	printf("m = %c\n", mystring_get(s, 24));
	printf("b = %c\n", mystring_get(s, 12));
	printf("z = %c\n", mystring_get(s, 15));
	printf("! = %c\n", mystring_get(s, 25));
        printf("  = %c\n", mystring_get(s, 23));
        printf("  = %c\n", mystring_get(s, 1));
        printf("s = %c\n", mystring_get(s, 500));
	if(mystring_get_len(s) == 501) {
		printf("getlen returns 501, success!\n");
	} else {

		printf("getlen does not return 501. Test failed!\n");
	}
	mystring_delete(s);

	s = mystring_new();
	mystring_cat(s, "hello ");
	mystring_cat(s, "world");
	printf("hello world = %s\n",mystring_get_data(s));
        mystring_delete(s);

	printf("Test complete.\n");
	
	return 0;
}
