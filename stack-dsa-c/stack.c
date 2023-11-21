struct sNode {
  char val;
  struct sNode *prev;
};

struct stack {
  int length;
  struct sNode *top;
};
typedef struct stack stack;
typedef struct sNode sNode;

stack* sConstructor () {
  stack * s = malloc(sizeof(stack));
  s->top = NULL;
  s->length = 0;
  return s;
}

void stackPush(stack *s, char value) {
  s->length++;
  sNode *node = malloc(sizeof(sNode));
  node->val = value;
  node->prev = s->top;
  s->top = node;
}

char stackPop(stack *s) {
  if(s->length == 0) {
    return -1;
  }
  s->length--;
  sNode *temp = s->top;
  char val = s->top->val;
  s->top = s->top->prev;
  free(temp);
  return val;
}

int isEmpty(stack *s) {
    return (s->length)? 0: 1;
}
