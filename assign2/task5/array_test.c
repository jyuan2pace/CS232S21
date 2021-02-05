//Do not modify this test file
#include <stdio.h>
#include <string.h>
#include <assert.h>

void bubbleSort(int[], int);
void printArray(int[], int);

int main() {

  int sorted[10] = {1,2,3,4,5,6,7,8,9,10};
  int reversed[10] = {10,9,8,7,6,5,4,3,2,1};
  int random[10] = {6,3,8,2,4,7,9,1,10,5};
  int single[1] = {0};

  bubbleSort(single,1);
  int single_element_sort_test = single[0];
  assert(single_element_sort_test == 0);

  bubbleSort(reversed,10);
  int reversed_sort_test = memcmp (sorted, reversed, sizeof(int)*10);
  assert(reversed_sort_test == 0);
  
  bubbleSort(random,10);
  int random_sort_test = memcmp (sorted, random , sizeof(int)*10);
  assert(random_sort_test == 0);
  
  return 0;
}
