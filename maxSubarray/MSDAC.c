#include <limits.h>

int maxSubArrayBF(int *A, int lo, int hi) {
  int sum, max_sum;
  max_sum = INT_MIN;
  for(int i = lo; i < hi; i++) {
    sum = 0;
    for(int j = i; j < hi; j++) {
      sum += A[j]; 
      if(max_sum < sum) {
        max_sum = sum;
      }
    }
  }
  return max_sum;
}

int maxCrossSubArray(int *A, int lo, int mid, int hi) {
  int left_sum, right_sum;
  left_sum = right_sum = INT_MIN;
  int sum = 0;
  for (int i = mid-1; i >= lo; i--) {
    sum += A[i];
    if(left_sum < sum) {
      left_sum = sum;
    }
  }
  sum = 0;
  for (int i = mid; i < hi; i++) {
    sum += A[i];
    if(right_sum < sum) {
      right_sum = sum;
    }
  }
  return left_sum + right_sum;
}

int maxSubArray(int *A, int lo, int hi) {
  if(hi - lo <= 50) {
    return maxSubArrayBF(A, lo, hi);
  } else {
    int mid = lo + (hi - lo) / 2;
    int sum_left = maxSubArray(A, lo, mid);
    int sum_right = maxSubArray(A, mid, hi);
    int sum_cross = maxCrossSubArray(A, lo, mid, hi);
    if(sum_left >= sum_right && sum_left >= sum_cross) {
      return sum_left;
    } else if(sum_right >= sum_left && sum_right >= sum_cross) {
      return sum_right;
    } else {
      return sum_cross;
    }
  }
}
