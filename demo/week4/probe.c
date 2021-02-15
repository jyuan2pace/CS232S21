#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int x;
static y;
int foo(int a, int b) {
  int c;
  c = a+b;
  return c;
}

char * bar(int size) {
  char * c = (char *) malloc(sizeof(char)*size);
  return c;
}

int main()
{
  int a=3, b=4;
  int c;
  char * s0 = "abc";
  char * s1, *s2;
  c= foo(3,4);
  printf("a+b=%d\n",c);

  c= foo(5,6);
  printf("a+b=%d\n",c);

  s1= bar(10);
  s1[0]='c';
  s2= bar(10);
  s2[1]='C';
  printf("&a=%p\n &b=%p\n &c=%p\n &s0=%p\n &s1=%p\n &s2=%p\n s0=%p\n s1=%p\n s2=%p\n",&a, &b, &c, &s0, &s1, &s2, s0, s1, s2);
  printf("addr of your code bar func = %p\n", bar);
  printf("addr of global x = %p, static y=%p\n", &x, &y);
} 

