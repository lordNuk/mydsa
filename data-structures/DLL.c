struct Node{
  int data;
  struct Node *next, *prev;
};

struct Node* newNode() {
  struct Node *n = (struct Node *)malloc(sizeof(struct Node));
  n->data = 0;
  n->next = NULL;
  n->prev = NULL;
  return n;
}

void insertAtBegDLL(struct Node **head, int v) {
  struct Node *n = newNode();
  n->data = v;
  n->next = *head;
  if(*head) {
    (*head)->prev = n;
  }
  *head = n;
}

void insertAtPosDLL(struct Node **head, int p, int v) {
  if(p == 1) {
    insertAtBegDLL(head, v);
    return;
  }
  struct Node *n = newNode(), *prev = *head;
  n->data = v;
  for(int i = 2; i < p; i++) {
    prev = prev->next;
  }
  n->next = prev->next;
  n->prev = prev;
  n->next->prev = n;
  prev->next = n;
}

void deleteAtPosLL(struct Node **head, int p) {
  struct Node *curr = *head;
  if(p == 1) {
    *head = curr->next;
    free(curr);
    return;
  }
  for(int i = 2; i < p; i++) {
    curr = curr->next;
  }
  struct Node *nodeToDel = curr->next;
  curr->next = nodeToDel->next;
  free(nodeToDel);
}

void reverseDLL(struct Node **head) {
  struct Node *curr = *head, *temp = NULL, *next;
  
  while(1) {
    next = curr->next;
    temp = curr->prev;
    curr->prev = curr->next;
    curr->next = temp;
    if(!next) {
      break;
    }
    curr = next;
  }
  *head = curr;
}

