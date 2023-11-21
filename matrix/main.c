#include <stdio.h>
#include "MMStar.c"
#include "MMR.c"

int main() {
  int **a = malloc(sizeof(int*)*3);
  for(int i = 0; i < 3; i++) {
    a[i] = malloc(sizeof(int)*3);
    for(int j = 0; j < 3; j++) {
      a[i][j] = i+j;
    }
  }
  int **b = malloc(sizeof(int*)*3);
  for(int i = 0; i < 3; i++) {
    b[i] = malloc(sizeof(int)*3);
    for(int j = 0; j < 3; j++) {
      b[i][j] = i+j;
    }
  }
  int **c = malloc(sizeof(int*)*3);
  for(int i = 0; i < 3; i++) {
    c[i] = malloc(sizeof(int)*3);
  }

  int **d = constructMatrix(3); 
  matrixMltplyRecursive(a, b, d, 0, 3, 0, 3, 0, 3);
  printf("result (recursive): \n");
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      printf("%2d ", d[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  starsenMatrixMultiplication(a, b, c, 0, 0, 0, 0, 0, 0, 3, 3);
  printf("result (starsen): \n");
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      printf("%2d ", c[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  free(a);
  free(b);
  free(c);
  free(d);

  return 0;
}
