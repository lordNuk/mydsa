#include "BT.c"
#include <stdio.h>

void inorderBT(node* n) {
  if(n == NULL) {
    return;
  }
  inorderBT(n->left);
  printf("%d ", n->val);
  inorderBT(n->right);
}

void preorderBT(node* n) {
  if(n == NULL) {
    return;
  }
  printf("%d ", n->val);
  preorderBT(n->left);
  preorderBT(n->right);
}

void postorderBT(node* n) {
  if(n == NULL) {
    return;
  }
  postorderBT(n->left);
  postorderBT(n->right);
  printf("%d ", n->val);
}

int main() {
  node* root = initTree();
  printf("\n\ninorder: \t\t");
  inorderBT(root);
  printf("\n\npreorder: \t\t");
  preorderBT(root);
  printf("\n\npostorder: \t\t");
  postorderBT(root);
  return 0;
}
