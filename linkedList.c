#include <stdio.h>
#include <stdlib.h>

struct node {
  struct node *next, *prev;
  int val;
};
struct linkedList {
  struct node *head, *tail;
  int length;
};

void initLL(struct linkedList *);
void prependLL(struct linkedList *, int);
void insertAtLL(struct linkedList *, int, int);
void appendLL(struct linkedList *, int);
void display(struct linkedList *);
int removeLL(struct linkedList *, int); 
int removeIndexLL(struct linkedList *, int); 
int getLL(struct linkedList *, int);

struct node * getAt(struct linkedList *, int);
int removeNode(struct linkedList *, struct node *); 

void initLL (struct linkedList *l) {
  l->head = l->tail = NULL;
  l->length = 0;
}

struct node * getAt(struct linkedList *l, int idx) {
  struct node *curr = l->head;
  for(int i = 0; curr && i < idx; i++) {
    curr = curr->next;
  }
  return curr;
}

int removeNode (struct linkedList *l, struct node *curr) {
  int val = curr->val;
  if(curr->prev) {
    curr->prev->next = curr->next;
  } else {
    l->head = curr->next;
  }
  if(curr->next) {
    curr->next->prev = curr->prev;
  } else {
    l->tail = curr->prev;
  }
  free(curr);
  return val;
}

void prependLL (struct linkedList *l, int val) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  l->length++;
  newNode->val = val;
  newNode->next = NULL;
  if(l->head == NULL) {
    l->head = l->tail = newNode;
    return;
  }
  newNode->next = l->head;
  l->head->prev = newNode;
  l->head = newNode;
}

void insertAtLL (struct linkedList *l, int val, int index) {
  if (index > l->length) {
    printf("unable to do that.... invalid index\n");
    return;
  } else {
    if (index == l->length) {
      appendLL(l, val);
      return;
    } else {
      if (index == 0) {
        prependLL(l, val);
        return;
      }
    }
  }
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  l->length++;
  newNode->val = val;
  struct node *curr = getAt(l, index);
  newNode->next = curr;
  newNode->prev = curr->prev;
  curr->prev = newNode;
  curr->prev->next = newNode;
}

void appendLL (struct linkedList *l, int val) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  l->length++;
  newNode->val = val;
  newNode->next = NULL;
  if(l->tail == NULL) {
    l->head = l->tail = newNode;
    return;
  }
  l->tail->next = newNode;
  newNode->prev = l->tail;
  l->tail = newNode;
}

int removeLL (struct linkedList *l, int val) {
  struct node *curr = l->head;
  for(int i = 0; i < l->length; i++) {
    if(curr->val == val) {
      break;
    }
    curr = curr->next;
  }
  if(!curr) {
    return -1;
  }
  l->length--;
  return removeNode(l, curr);
}

int removeIndexLL(struct linkedList *l, int idx) {
  struct node *curr = getAt(l, idx);
  if(!curr) {
    return -1;
  }
  l->length--;
  return removeNode(l, curr);
}

int getLL (struct linkedList *l, int idx) {
  struct node *curr = getAt(l, idx);
  if(!curr) {
    return -1;
  }
  return curr->val;
}

void display (struct linkedList *l) {
  printf("your linkedList: \t\thead -> ");
  struct node * temp = l->head;
  while(temp) {
    printf("%d -> ", temp->val);
    temp = temp->next;
  }
  printf("null\n");
}
