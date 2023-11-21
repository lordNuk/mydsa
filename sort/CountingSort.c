void CountingSort(int *a, int n, int k) {
  int b[k], c[n];
  for(int i = 0; i<k; i++) {
    b[i] = 0;
  }
  for(int i = 0; i<n; i++) {
    b[a[i]]++;
  }
  for(int i = 1; i<k; i++) {
    b[i] += b[i-1];
  }
  for(int i = n-1; i>=0; i--) {
    c[b[a[i]] - 1] = a[i];
    b[a[i]]--;
  }
  for(int i = 0; i<n; i++) {
    a[i] = c[i];
  }
}
