#include <stdlib.h>

void heapifyDown (int); 
void heapifyUp (int); 
int rightChild (int); 
int leftChild (int); 
int parent (int); 
struct heapNode {
  int val;
  struct heapNode *leftChild, *rightChild;
};
typedef struct heapNode heapNode;

heapNode minHeap[100];
int minHeapLength = 0;

void insertHeap (int val) {
  minHeap[minHeapLength].val = val;
  heapifyUp(minHeapLength);
  minHeapLength++;
}

int popHeap () {
  if(minHeapLength <= 0) {
    return -1;
  }
  minHeapLength--;
  int out = minHeap[0].val;
  if(minHeapLength == 0) {
    return out;
  }
  minHeap[0].val = minHeap[minHeapLength].val;
  heapifyDown(0);
  return out; 
}

// helper funcitons: --v 

int leftChild (int idx) {
  return idx * 2 + 1;
}
int rightChild (int idx) {
  return idx * 2 + 2;
}
int parent (int idx) {
  return (idx-1) / 2;
}
void heapifyUp (int idx) {
  // swap with the parent node untill it is smaller than it parent or is at top

  if (idx == 0) {
    return ;
  }
  int v = minHeap[idx].val;
  int p = parent (idx);
  int parentV = minHeap[p].val;
  if (parentV > v) {
    minHeap[p].val = v;
    minHeap[idx].val = parentV;
    heapifyUp(p);
  }
}
void heapifyDown (int idx) {
  // swap the root node with the child node till it is smaller than its child or is at bottom
  int l = leftChild(idx);
  int r = rightChild(idx);
  int v = minHeap[idx].val;
  int lv = minHeap[l].val;
  int rv = minHeap[r].val;
  if (idx >= minHeapLength-1) {
    return;
  }
  if(lv < rv && lv < v) {
    minHeap[idx].val = lv;
    minHeap[l].val = v;
    heapifyDown(l);
  } else if(rv < lv && rv < v) {
    minHeap[idx].val = rv;
    minHeap[r].val = v;
    heapifyDown(r);
  }
}
