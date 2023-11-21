void matrixMltplyBf(int **a, int **b, int **c, int ar, int ac, int bc) {
  for(int i = 0; i < ar; i++) {
    for(int j = 0; j < bc; j++) {
      c[i][j] = 0;
      for(int k = 0; k < ac; k++) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }
}
