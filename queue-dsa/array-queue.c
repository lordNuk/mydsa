#define MAXSIZE 10
int myQ[MAXSIZE];

int front = -1, rear = -1;

void incPointer(int *a) {
    (*a)++;
    if((*a) == MAXSIZE) {
        (*a) = 0;
    }
}

int isEmpty() {
    if(front == rear && front == -1) {
        return 1;
    }
    return 0;
}

int isFull() {
    if(rear == front && !isEmpty() ) {
        return 1;
    }
    return 0;
}

void enqueue(int val) {
    if(isFull()) {
        printf("queue is full.\n");
        return;
    }
    if(isEmpty()) {
        front = rear = 0;
    }
    myQ[rear] = val;
    incPointer(&rear);
}

int dequeue() {
    if(isEmpty()) {
        return -1;
    }
    int val = myQ[front];
    incPointer(&front);
    if(isFull()) {
        front = rear = -1;
    }
    return val;
}

