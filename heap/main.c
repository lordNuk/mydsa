#include<stdio.h>
#include"heap.h"

void display_heap(int *a, int *hs) {
  int n = *hs;
  for(int i = 0; i<n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

int main() {
  int h[100] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
  int heap_size = 10;
  construct_max_heap(h, &heap_size);
  printf("max_heap: ");
  display_heap(h, &heap_size);
  int c = 0, knew = 0;
  while(1) {
    printf("\ninsert in max_heap?(1/0) ");
    scanf("%d", &c);
    if(!c) {
      break;
    }
    printf("\nnew val: ");
    scanf("%d", &knew);
    max_heap_insert(h, knew, &heap_size);
    printf("updated_heap: ");
    display_heap(h, &heap_size);
  }
  printf("have a nice day. bye!\n");

  return 0;
}
