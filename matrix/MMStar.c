#include <stdlib.h>
#include <stdio.h>

int** constructMatrix(int len) {
  int **m = malloc(sizeof(int*)*len);
  for(int i = 0; i < len; i++) {
    m[i] = malloc(sizeof(int)*len);
    for(int j = 0; j < len; j++) {
      m[i][j] = 0;
    }
  }
  return m;
}
void starsenMatrixMultiplication(int **a, int **b, int **c, int ar, int ac, int br, int bc, int cr, int cc, int n, int max) {
  if(n < 1) {
    return;
  }
  if(n < 2) {
    c[cr][cc] += a[ar][ac] * b[br][bc];
    return;
  }
  int len = n/2;
  int altLen = len + n%2; 
  int **s1, **s2, **s3, **s4, **s5, **s6, **s7, **s8, **s9, **s10, **p1, **p2, **p3, **p4, **p5, **p6, **p7;
  s1 = constructMatrix(altLen); s2 = constructMatrix(altLen); s3 = constructMatrix(altLen); s4 = constructMatrix(altLen);
  s5 = constructMatrix(altLen); s6 = constructMatrix(altLen); s7 = constructMatrix(altLen); s8 = constructMatrix(altLen);
  s9 = constructMatrix(altLen); s10 = constructMatrix(altLen); p1 = constructMatrix(altLen); p2 = constructMatrix(altLen);
  p3 = constructMatrix(altLen); p4 = constructMatrix(altLen); p5 = constructMatrix(altLen); p6 = constructMatrix(altLen);
  p7 = constructMatrix(altLen);
  for(int i = 0; i < altLen; i++) {
    for(int j = 0; j < altLen; j++) {
      int ar1, ar2, ac1, ac2, br1, br2, bc1, bc2;
      ar1 = ar + i;
      ar2 = ar + altLen + i;
      ac1 = ac + j;
      ac2 = ac + altLen + j;
      br1 = br + i;
      br2 = br + altLen + i;
      bc1 = bc + j;
      bc2 = bc + altLen + j;
      
      // s1 = b12 - b22
      s1[i][j] = ((j == len || bc2 <= max)? 0 : b[br1][bc2]) - ((j == len || i == len || br2 >= max || bc2 >= max)? 0 : b[br2][bc2]);
      // s2 = a11 + a12
      s2[i][j] = a[ar1][ac1] + ((j == len || ac2 >= max)? 0: a[ar1][ac2]);
      // s3 = a21 + a22
      s3[i][j] = (i == len || ar2 >= max)? 0 : a[ar2][ac1] + ((j == len || i == len || ar2 >= max || ac2 >= max)? 0 : a[ar2][ac2]);
      // s4 = b21 - b11
      s4[i][j] = ((i == len || br2 >= max)? 0 : b[br2][bc1]) - b[br1][bc1];
      // s5 = a11 + a22
      s5[i][j] = a[ar1][ac1] + ((j == len || i == len || ar2 >= max || ac2 >= max)? 0 : a[ar2][ac2]);
      // s6 = b11 + b22
      s6[i][j] = b[br1][bc1] + ((j == len || i == len)? 0 : (br2 >= max || bc2 >= max)? 0: b[br2][bc2]);
      // s7 = a12 - a22
      s7[i][j] = ((j == len || ac2 >= max)? 0 : a[ar1][ac2]) - ((j == len || i == len || ar2 >= max || ac2 >= max)? 0 : a[ar2][ac2]);
      // s8 = b21 + b22
      s8[i][j] = ((i == len || br2 >= max)? 0 : b[br2][bc1]) + ((j == len || i == len || br2 >= max || bc2 >= max)? 0 : b[br2][bc2]);
      // s9 = a11 - a21
      s9[i][j] = a[ar1][ac1] - ((i == len || ar2 >= max)? 0 : a[ar2][ac1]);
      // s10 = b11 + b12
      s10[i][j] = b[br1][bc1] + ((j == len || bc2 >= max)? 0 : b[br1][bc2]);
    }
  }
// p1 = a11.s1
  starsenMatrixMultiplication(a, s1, p1, ar, ac, 0, 0, 0, 0, altLen, max);
// p2 = s2.b22
  if(br+altLen < max && bc+altLen < max)
    starsenMatrixMultiplication(s2, b, p2, 0, 0, br+altLen, bc+altLen, 0, 0, altLen, max);
// p3 = s3.b11
  starsenMatrixMultiplication(s3, b, p3, 0, 0, br, bc, 0, 0, altLen, max);
// p4 = a22.s4
  if(ar+altLen < max && ac+altLen < max)
    starsenMatrixMultiplication(a, s4, p4, ar+altLen, ac+altLen, 0, 0, 0, 0, altLen, max);
// p5 = s5.s6
  starsenMatrixMultiplication(s5, s6, p5, 0, 0, 0, 0, 0, 0, altLen, max);
// p6 = s7.s8
  starsenMatrixMultiplication(s7, s8, p6, 0, 0, 0, 0, 0, 0, altLen, max);
// p7 = s9.s10
  starsenMatrixMultiplication(s9, s10, p7, 0, 0, 0, 0, 0, 0, altLen, max);

  for(int i = 0; i < altLen; i++) {
    for(int j = 0; j < altLen; j++) {
// c11 += p5 + p4 - p2 + p6
      c[cr+i][cc+j] += p5[i][j] + p4[i][j] - p2[i][j] + p6[i][j]; 
// c12 += p1 + p2
      if(j < len) 
        c[cr+i][cc+j+altLen] += p1[i][j] + p2[i][j]; 
// c21 += p3 + p4
      if(i < len) 
        c[cr+i+altLen][cc+j] += p3[i][j] + p4[i][j]; 
// c22 += p5 + p1 - p3 - p7
      if(i < len && j < len) 
        c[cr+i+altLen][cc+j+altLen] += p5[i][j] + p1[i][j] - p3[i][j] - p7[i][j]; 
    }
  }
  free(s1);
  free(s2);
  free(s3);
  free(s4);
  free(s5);
  free(s6);
  free(s7);
  free(s8);
  free(s9);
  free(s10);
  free(p1);
  free(p2);
  free(p3);
  free(p4);
  free(p5);
  free(p6);
  free(p7);
}
