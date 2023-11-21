#include <stdio.h>
#include <stdlib.h>
#include "BT.c"

struct queueNode {
  tnode* node;
  struct queueNode* next;
};
typedef struct queueNode queueNode;

struct queue {
  queueNode * head;
  queueNode * tail;
  int length;
};

struct queue * initQueue (tnode * root) {
  struct queue * q = (struct queue *)malloc(sizeof(struct queue));
  queueNode * newnode = (queueNode *)malloc(sizeof(queueNode));
  newnode->node = root;
  newnode->next = NULL;
  q->length = 1;
  q->head = q->tail = newnode;
  return q;
};

typedef struct queue queue;

void enqueue(queue * q, tnode * t) {
  queueNode *n = (queueNode *)malloc(sizeof(queueNode));
  n->node = t;
  n->next = NULL;

  q->length++;
  if(q->length == 1) {
    q->head = q->tail = n;
    return;
  }
  q->tail->next = n;
  q->tail = n;
}

int dequeue(queue * q) {
  q->length--;
  queueNode *temp = q->head;
  int val = temp->node->val;
  q->head = q->head->next; 
  if(q->length == 0) {
    q->head = q->tail = NULL;
  }
  free(temp);
  return val; 
}


int breadthFsearch (tnode* root, int val) {
  struct queue * q = initQueue(root);
  int res = -1;
  printf("\n\nyour tree: \t");
  while(q->length >= 1) {
    if(q->head->node->left){
      enqueue(q, q->head->node->left);
    }
    if(q->head->node->right){
      enqueue(q, q->head->node->right);
    }

    int d = dequeue(q); 
    if (d == val) {
      res = val;
    }
    printf("%d ", d); 
  }
  return res;
}

int main() {
  tnode * root = initTree();
  int val = -1;
  printf("find? : ");
  scanf("%d", &val);
  int res = breadthFsearch(root, val);
  printf("\n\nres: %d", res);
  return 0;
}
