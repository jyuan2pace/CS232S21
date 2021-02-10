#include <stdio.h>
#include <string.h>
void swap1(int a, int b){
  int temp = a;
  a = b;
  b = temp;
}
void swap2(int* p_a, int* p_b){
  int temp = *p_a;
  *p_a = *p_b;
  *p_b = temp;
}
int main()
{
  int a=3, b=4;
  printf("before swap1, a=%d, b=%d\n",a,b);
  swap1(a, b);
  printf("after swap1, a=%d, b=%d\n",a,b);
  swap2(&a, &b);
  printf("after swap2, a=%d, b=%d\n",a,b);

} 