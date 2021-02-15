#include <stdio.h>
#include <string.h>

int* swap1(int a, int b){
  int * arr = (int *)malloc(sizeof(int)*2) ;
  arr[0] = b;
  arr[1] = a;
  return arr;
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
  int * p =swap1(a, b)
  a = p[0];
  b = p[1];

  free(p);
  //p[0]->b
  //p[1]->a
  printf("after swap1, a=%d, b=%d\n",a,b);
  swap2(&a, &b);
  printf("after swap2, a=%d, b=%d\n",a,b);

} 
