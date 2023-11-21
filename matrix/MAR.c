void matrixSumRecursive(int **a, int **b, int **c, int rs, int re, int cs, int ce) {
  if(re-rs < 1 || ce-cs < 1) {
    return;
  }
  if(re-rs == 1 && ce-cs == 1) {
    c[rs][cs] = a[rs][cs] + b[rs][cs];
    return;
  }
  int rm = rs + (re - rs) / 2;
  int cm = cs + (ce - cs) / 2;

  matrixSumRecursive(a, b, c, rs, rm, cs, cm);
  matrixSumRecursive(a, b, c, rs, rm, cm, ce);
  matrixSumRecursive(a, b, c, rm, re, cs, cm);
  matrixSumRecursive(a, b, c, rm, re, cm, ce);
}
