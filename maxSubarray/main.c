#include <stdio.h>
#include "MSDAC.c"
#include "MSLS.c"
#include <time.h>

int main() {
  int a[] = {-4, 7, 13, -3, -25, 20, -3, -16, -23, 18, -4, 7, 13, -3, -25, 20, -3, -16, -23, 18, -4, 7, 13, -3, -25, 20, -3, -16, -23, 18, -4, 7, 13, -3, -25, 20, -3, -16, -23, 18, -4, 7, 13, -3, -25, 20, -3, -16, -23, 18, -4, 7, 13, -3, -25, 20, -3, -16, -23, 18, -4, 7, 13, -3, -25, 20, -3, -16, -23, 18, -4, 7, 13, -3, -25, 20, -3, -16, -23, 18, -4, 7, 13, -3, -25, 20, -3, -16, -23, 18, -4, 7, 13, -3, -25, 20, -3, -16, -23, 18};
  printf("finding max subarray sum....");
  clock_t t = clock();
  int sum = maxSubArray(a, 0, 100);
  double t1 = (double)(clock() - t) / CLOCKS_PER_SEC;
  t = clock();
  int bFsum = maxSubArrayBF(a, 0, 100);
  double t2 = (double)(clock() - t) / CLOCKS_PER_SEC;
  t = clock();
  int Lsum = maxSubArrayLinear(a, 0, 100);
  double t3 = (double)(clock() - t) / CLOCKS_PER_SEC;
  printf("\nmax subarray sum= %d (%f)", sum, t1);
  printf("\nmax subarray bFsum= %d (%f)", bFsum, t2);
  printf("\nmax subarray Lsum= %d (%f)", Lsum, t3);
  printf("\n\n");
  return 0;
}
