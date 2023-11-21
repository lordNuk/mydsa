#include <stdio.h> 
#include "mergeSort.c"

int main() {
  int a[] = {8, 23, 1, 43, 1, 99, 2};
  printf("preforming merge sort....");
  mergeSort(a, 0, 7);
  printf("\nmerge sort done!\n");
  for(int i = 0; i<7; i++)
    printf("%d ", a[i]);
  printf("\n\n");
  return 0;
}
