#include <stdio.h>

int partition (int *arr, int lo, int hi) {
  int idx = lo - 1;
  int pivot = arr[hi];
  for (int i = lo; i < hi; i++) {
    if (arr[i] <= pivot) {
      idx++;
      int temp = arr[i];
      arr[i] = arr[idx];
      arr[idx] = temp;
    }
  }
  idx++;
  arr[hi] = arr[idx];
  arr[idx] = pivot;
  return idx;
}

void qs (int *arr, int lo, int hi) {
  if( lo >= hi ) {
    return;
  }
  int pivot = partition(arr, lo, hi);
  qs(arr, lo, pivot-1);
  qs(arr, pivot+1, hi);
}
void display (int *list) {
  for (int i = 0; i < 8; i++) {
    printf("%d\t", list[i]);
  }
  printf("\n");
}

int main() {
  int list[] = {11, 32, 6, 3, 9, 34, 2, 1};
  printf("list:");
  display(list);
  qs(list, 0, 7);
  printf("sorted list:");
  display(list);
  printf("done!");
  return 0;
}
























