#include <stdio.h>

int main(void) {
	printf("%u bytes needed to store a char\n", sizeof(char));
	printf("%u bytes needed to store a short\n", sizeof(short));
	printf("%u bytes needed to store an int\n", sizeof(int));
	printf("%u bytes needed to store a long\n", sizeof(long));
	printf("%u bytes needed to store a double\n", sizeof(double));
	return 0;
}
