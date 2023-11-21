#include <stdlib.h>

struct sNode {
  int val;
  struct sNode *prev;
};

struct stack {
  int length;
  struct sNode *top;
};

typedef struct sNode sNode;
typedef struct stack stack;

stack* sConstructor () {
  stack * s = malloc(sizeof(stack));
  s->top = NULL;
  s->length = 0;
  return s;
}

void push(stack *s, int value) {
  s->length++;
  sNode *node = malloc(sizeof(sNode));
  node->val = value;
  node->prev = s->top;
  s->top = node;
}

int pop(stack *s) {
  if(s->length == 0) {
    return -1;
  }
  s->length--;
  sNode *temp = s->top;
  int val = s->top->val;
  s->top = s->top->prev;
  free(temp);
  return val;
}

int stackPeek(stack *s) {
  return (s->top == NULL)? -1: s->top->val;
}
