#include <limits.h>

int maxSubArrayBF(int *A, int len) {
  int sum, max_sum;
  max_sum = INT_MIN;
  for(int i = 0; i < len; i++) {
    sum = 0;
    for(int j = i; j < len; j++) {
      sum += A[j]; 
      if(max_sum < sum) {
        max_sum = sum;
      }
    }
  }
  return max_sum;
}
