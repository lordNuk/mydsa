#include<stdio.h>
#include "array-queue.c"


void display() {
    if(isEmpty()) {
        printf("queue is empty!\n");
        return;
    }
    int i = front;
    do {
        printf("%d ", myQ[i]);
        i++;
        i %= MAXSIZE;
    } while(i != rear);
    printf("\n");
}

int main() {
    enqueue(4);
    enqueue(5);
    enqueue(3);
    enqueue(0);
    enqueue(1);
    display();     // 4 5 3 0 1
    enqueue(11);
    enqueue(12);
    enqueue(10);
    enqueue(7);
    enqueue(8);
    display();      // 4 5 3 0 1 11 12 10 7 8
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    enqueue(4);
    enqueue(5);
    enqueue(3);
    enqueue(0);
    display();      // 1 11 12 10 7 8 4 5 3 0
    return 0;
}












