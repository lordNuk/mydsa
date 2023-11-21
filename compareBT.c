// dfs used for structural check of the binarry trees
// 1 base condition to check the structure
// 2nd base condition to check for structure + values

#include "BT.c"

int compareBTs(tnode *a, tnode *b) {
  if(a == NULL && b == NULL) {
    return 1;
  }
  if(a->val != b->val) {
    return 0;
  }
   return compareBTs(a->left, b->left) && compareBTs(a->right, b->right);
}
