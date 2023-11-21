#include<stdio.h>
#include<stdlib.h>
#include "DLL.c"

void displayLL(struct Node *head) {
  struct Node *n = head;
  if(!head) {
    printf("# linked list: empty\n");
    return;
  }
  printf("# linked list: \n");
  while(n) {
    printf("%d -> ", n->data);
    n = n->next;
  }
  printf("NULL\n");
}

int main() {
  struct Node *head = NULL;
  insertAtBegDLL(&head, 10);
  insertAtBegDLL(&head, 9);
  insertAtBegDLL(&head, 8);
  insertAtBegDLL(&head, 7);
  insertAtBegDLL(&head, 6);
  insertAtBegDLL(&head, 5);
  insertAtBegDLL(&head, 4);
  insertAtBegDLL(&head, 3);
  insertAtBegDLL(&head, 2);
  insertAtBegDLL(&head, 1);
  displayLL(head);
  printf("reversing LL\n");
  reverseDLL(&head);
  displayLL(head);
  return 0;
}
/* #### for linked list insertion deletion
int main() {
  struct Node *head = NULL;
  int c = 0;
  printf("enter choice:\n1: insert at beg\t\t2: insert at pos\n3: delete at pos\t\t4: display list\n0: exit\n");
  while(1) {
    scanf("%d", &c);
    switch (c) {
      case 0: return 0;
      case 1: {
                int val = 0;
                printf("enter val:  ");
                scanf("%d", &val);
                insertAtBegDLL(&head, val);
              } break;
      case 2: {
                int val = 0, pos = 0;
                printf("enter pos:  ");
                scanf("%d", &pos);
                printf("enter val:  ");
                scanf("%d", &val);
                insertAtPosDLL(&head, pos, val);
              } break;
      case 3: {
                int pos = 0;
                printf("enter pos:  ");
                scanf("%d", &pos);
                deleteAtPosLL(&head, pos);
              } break;
      case 4: {
                displayLL(head);
              } break;
      default: {
                printf("invalid choice!\n"); 
                printf("enter choice:\n1: insert at beg\t\t2: insert at pos\n0: exit\n");
              }
    }
  }
  return 0;
}
*/
