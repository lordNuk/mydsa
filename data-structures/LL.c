struct Node{
  int data;
  struct Node *next;
};

struct Node* newNode() {
  struct Node *n = (struct Node *)malloc(sizeof(struct Node));
  n->next = NULL;
  return n;
}

void insertAtBegLL(struct Node **head, int v) {
  struct Node *n = newNode();
  n->data = v;
  n->next = *head;
  *head = n;
}

void insertAtPosLL(struct Node **head, int p, int v) {
  if(p == 1) {
    insertAtBegLL(head, v);
    return;
  }
  struct Node *n = newNode(), *curr = *head;
  n->data = v;
  for(int i = 2; i < p; i++) {
    curr = curr->next;
  }
  n->next = curr->next;
  curr->next = n;
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
