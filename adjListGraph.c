#include <stdlib.h>

struct gListNode {
  int weight, to;
  struct gListNode *next;
};

struct gList {
  struct gListNode *head, *tail;
  int length;
};

typedef struct gListNode gListNode;
typedef struct gList gList;

gList* adjListConstructor () {
  gList* q = malloc(sizeof(gList));
  q->head = q->tail = NULL;
  q->length = 0;
  return q;
}

void ALenqueue(gList *q, int to, int weight) {
  q->length++;
  gListNode *node = malloc(sizeof(gListNode));
  node->to = to;
  node->weight = weight;
  node->next = NULL;
  if(q->head == NULL){
    q->head = q->tail = node;
    return;
  }
  q->tail->next = node;
  q->tail = node;
}

int ALdequeue(gList *q) {
  if(q->length == 0) {
    return -1;
  }
  q->length--;
  gListNode *temp = q->head;
  int to = temp->to;
  if(q->head == q->tail){
    q->head = q->tail = NULL;
  } else {
    q->head = q->head->next;
  }
    free(temp);
    return to;
}

gListNode* ALget(gList *g, int idx) {
  int i;
  gListNode* curr = g->head;
  for(i = 0; i < idx; i++) {
    curr = curr->next;
  }
  return curr;
}
