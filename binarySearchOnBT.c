#include "BT.c"
#include <stdio.h>

int binarySearchOnBT (tnode *b, int val) {
  if(b == NULL)
    return 0;
  if(b->val == val) 
    return 1;
  if(b->val > val)
    return binarySearchOnBT(b->left, val);
  return binarySearchOnBT(b->right, val);
}

int main() {
  tnode *t = initTree(7);
  int val = 0;
  while(1) {
    printf("Enter value to be serached: \t");
    scanf("%d", &val);
    if (val == -1)
      break;
    if (binarySearchOnBT(t, val))
      printf("value found!\n");
    else 
      printf("value not found!\n");
  }
  return 0;
}
