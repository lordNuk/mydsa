void matrixMltplyRecursive(int **a, int **b, int **c, int arl, int arh, int acl, int ach, int bcl, int bch) {
  if(arh-arl < 1 || ach - acl < 1 || bch - bcl < 1)
    return;
  if(arh - arl == 1 && ach - acl == 1 && bch - bcl == 1) {
    c[arl][bcl] += a[arl][acl] * b[acl][bcl];
    return;
  }
  int arm = arl + (arh - arl) / 2;
  int acm = acl + (ach - acl) / 2;
  int bcm = bcl + (bch - bcl) / 2;

  matrixMltplyRecursive(a, b, c, arl, arm, acl, acm, bcl, bcm);
  matrixMltplyRecursive(a, b, c, arl, arm, acm, ach, bcl, bcm);

  matrixMltplyRecursive(a, b, c, arl, arm, acl, acm, bcm, bch);
  matrixMltplyRecursive(a, b, c, arl, arm, acm, ach, bcm, bch);

  matrixMltplyRecursive(a, b, c, arm, arh, acl, acm, bcl, bcm);
  matrixMltplyRecursive(a, b, c, arm, arh, acm, ach, bcl, bcm);

  matrixMltplyRecursive(a, b, c, arm, arh, acl, acm, bcm, bch);
  matrixMltplyRecursive(a, b, c, arm, arh, acm, ach, bcm, bch);
}
