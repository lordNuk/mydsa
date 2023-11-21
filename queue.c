#include <stdlib.h>

struct qNode {
  int val;
  struct qNode *next;
};

struct queue {
  int length;
  struct qNode *head, *tail;
};

typedef struct qNode qNode;
typedef struct queue queue;

queue* qConstructor () {
  queue * q = malloc(sizeof(queue));
  q->head = q->tail = NULL;
  q->length = 0;
  return q;
}

void enqueue(queue *q, int value) {
  q->length++;
  qNode *node = malloc(sizeof(qNode));
  node->val = value;
  node->next = NULL;
  if(q->head == NULL){
    q->head = q->tail = node;
    return;
  }
  q->tail->next = node;
  q->tail = node;
}

int dequeue(queue *q) {
  if(q->length == 0) {
    return -1;
  }
  q->length--;
  qNode *temp = q->head;
  int val = temp->val;
  if(q->head == q->tail){
    q->head = q->tail = NULL;
  } else {
    q->head = q->head->next;
  }
    free(temp);
    return val;
}

int queuePeek(queue *q) {
  return (q->head == NULL)? -1: q->head->val;
}
