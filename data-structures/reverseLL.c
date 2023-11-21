void reverseLL(struct Node **head) {
  struct Node *curr = *head;
  struct Node *prev = NULL, *next = NULL;

  while(curr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  *head = prev;
}

void reverseLLRec(struct Node **head, struct Node *curr) {
  if(!curr->next) {
    *head = curr;
    return;
  }
  reverseLLRec(head, curr->next);
  curr->next->next = curr;
  curr->next = NULL;
}

/*
void reverseLLRec(struct Node **head, struct Node *prev, struct Node *curr) {
  if(!curr) {
    *head = prev;
    return;
  }
  reverseLLRec(head, curr, curr->next);
  curr->next = prev;
}
*/
