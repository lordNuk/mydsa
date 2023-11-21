#include<stdio.h>
#include "RadixSort.c"

void mdisplay (int *list, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d\t", list[i]);
  }
  printf("\n");
}

int main() {
  int list[] = {329, 457, 657, 839, 436, 720, 355};
  printf("list:\t\t");
  mdisplay(list, 7);
  RadixSort(list, 7, 3);
  printf("sorted list:\t");
  mdisplay(list, 7);
  printf("done!\n");
  return 0;
}

