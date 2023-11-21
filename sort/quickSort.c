#include "./../swap.c"
#include "./../Random.c"
#include <stdio.h>

int hoarePartition (int *a, int lo, int hi) {
  int p = a[hi];
  int i = lo, j = hi;
  while (i<j) {
    while(j>lo && a[j] >= p){
      j--;
    }
    while(i<hi && a[i] < p){
      i++;
    } 
    if(i<j) {
      swap(&a[i], &a[j]);
    } 
  }
  swap(&a[i], &a[hi]);
  return i;
}

int partition (int *a, int lo, int hi) {
  int idx = lo-1;
  int p = a[hi];
  for(int i = lo; i<hi; i++) {
    if(p>=a[i]) {
      ++idx;
      swap(&a[i], &a[idx]);
    }
  }
  idx++;
  swap(&a[idx], &a[hi]);
  return idx;
}

int randomPartition (int *a, int lo, int hi) {
  int piv = getRandom(lo, hi+1);
  swap(&a[piv], &a[hi]);
  hoarePartition(a, lo, hi);
}

void qs (int *arr, int lo, int hi) {
  if( lo >= hi-1) {
    return;
  }
  int pivot = randomPartition(arr, lo, hi);
  qs(arr, lo, pivot-1);
  qs(arr, pivot+1, hi);
}
