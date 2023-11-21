int maxSubArrayLinear(int *A, int lo, int hi) {
  int max, current_max;
  max = current_max = 0;   
  for(int i = lo; i < hi; i++) {
    current_max += A[i];
    if(current_max <= 0) {
      current_max = 0;
    }
    if(current_max > max) {
      max = current_max;
    }
  }
  return max;
}
