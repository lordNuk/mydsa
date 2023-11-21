void CountingSortR(int *a, int n, int d) {
  int k = 10;
  int b[k], c[n];
  for(int i = 0; i<k; i++) {
    b[i] = 0;
  }
  for(int i = 0; i<n; i++) {
    b[(a[i]/d)%10]++;
  }
  for(int i = 1; i<k; i++) {
    b[i] += b[i-1];
  }
  for(int i = n-1; i>=0; i--) {
    c[b[(a[i]/d)%10] - 1] = a[i];
    b[(a[i]/d)%10]--;
  }
  for(int i = 0; i<n; i++) {
    a[i] = c[i];
  }
}
void RadixSort(int *a, int n, int d) {
  int p = 1;
  for(int i = 0; i<d; i++) {
    CountingSortR(a, n, p);
    p *= 10;
  }
}
