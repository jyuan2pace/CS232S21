#include <stdio.h>

int main(void) {
	printf("=======unsigned vs 2's complement demo=====\n");
	printf("=======char from quote ====================\n");
	char a = 'a';
	printf("a=%c\n", a);
	printf("a=%hhu\n", a);
	printf("a=%hhi\n", a);
	printf("=======char from numeric===================\n");
	char b= 143;
	printf("a=%c\n", b);
	printf("a=%hhu\n", b);
	printf("a=%hhi\n", b);
	printf("=======short ==============================\n");
	unsigned short c = 0xffff;
	printf("b=%hu\n", c);
	printf("b=%hi\n", c);
	printf("=======unsigned int=== ====================\n");
	unsigned int d = 0xffffffff;
	printf("b=%u\n", d);
	printf("b=%i\n", d);
	return 0;
}
