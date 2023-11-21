#include <stdlib.h>

struct tnode {
  int val;
  struct tnode * left;
  struct tnode * right;
};
typedef struct tnode tnode;
tnode * initTree (int a) {
  tnode* tree = (tnode*) malloc (sizeof(tnode));
  tree->val = 4;
  tree->left = (tnode *)malloc(sizeof(tnode)); 
  tree->right = (tnode *)malloc(sizeof(tnode)); 

  tree->left->val = 2;
  tree->left->left = (tnode *)malloc(sizeof(tnode)); 
  tree->left->right = (tnode *)malloc(sizeof(tnode)); 

  tree->left->left->val = 1; 
  tree->left->left->left = NULL; 
  tree->left->left->right = NULL; 
  tree->left->right->val = 3; 
  tree->left->right->left = NULL; 
  tree->left->right->right = NULL; 

  tree->right->val = 6;
  tree->right->left = (tnode *)malloc(sizeof(tnode)); 
  tree->right->right = (tnode *)malloc(sizeof(tnode)); 

  tree->right->left->val = 5; 
  tree->right->left->left = NULL; 
  tree->right->left->right = NULL; 
  tree->right->right->val = a; 
  tree->right->right->left = NULL; 
  tree->right->right->right = NULL; 
  return tree;
}
