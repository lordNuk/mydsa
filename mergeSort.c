#include <stdlib.h>

void merge(int *a, int l, int m, int r) {
  int n1 = m-l, n2 = r-m, *L, *R;
  L = malloc(sizeof(int)*n1);
  R = malloc(sizeof(int)*n2);
  for(int i = 0, k = l; i<n1; i++, k++)
    L[i] = a[k];
  for(int i = 0, k = m; i<n2; i++, k++)
    R[i] = a[k];
  int i = 0, j = 0, k = l;
  while(i<n1 && j<n2) {
    if(L[i] <= R[j]) {
      a[k] = L[i];
      i++;
    } else {
      a[k] = R[j];
      j++;
    }
    k++;
  }
  while(i<n1) {
    a[k] = L[i];
    k++; i++;
  }
  while(j<n1) {
    a[k] = R[j];
    k++; j++;
  }
}

void mergeSort(int *a, int lo, int hi) {
  if(lo >= hi-1) {
    return;
  }
  int mid = lo + (hi-lo)/2;
  mergeSort(a, lo, mid);
  mergeSort(a, mid, hi);
  merge(a, lo, mid, hi);
}
