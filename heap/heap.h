#include"../swap.c"
void max_heapify(int *h, int i, int *heap_size);
void min_heapify(int *h, int i, int *heap_size);
void construct_max_heap(int *h, int *heap_size);
void construct_min_heap(int *h, int *heap_size);
int max_heap_increase_key(int *h, int kold, int knew, int *heap_size);
int max_heap_maximum(int *h, int *heap_size);
int max_heap_extract_maximum(int *h, int *heap_size);
void max_heap_insert(int *h, int knew, int *heap_size);
int parent_index(int c);
int child_index(int p);

int child_index(int p) {
  return p*2 + 1;
}
int parent_index(int c) {
  return (--c)/2;
}

void max_heapify(int *h, int i, int *heap_size) {
  int max;
  int lchild, rchild;
  lchild = i*2 + 1;
  rchild = lchild+1;
  if(lchild < *heap_size && h[i] < h[lchild]) {
    max = lchild;
  } else {
    max = i;
  } 
  if(rchild < *heap_size && h[max] < h[rchild]) {
    max = rchild;
  }
  if(max != i) {
    swap(&h[i], &h[max]);
    max_heapify(h, max, heap_size);
  }
}

void min_heapify(int *h, int i, int *heap_size) {
  int min;
  int lchild, rchild;
  lchild = i*2 + 1;
  rchild = lchild+1;
  if(lchild < *heap_size && h[i] > h[lchild]) {
    min = lchild;
  } else {
    min = i;
  } 
  if(rchild < *heap_size && h[min] > h[rchild]) {
    min = rchild;
  }
  if(min != i) {
    swap(&h[i], &h[min]);
    min_heapify(h, min, heap_size);
  }
}

int max_heap_increase_key(int *h, int i, int knew, int *heap_size) {
  if(i >= *heap_size || h[i] >= knew) {
    return 0;
  }
  h[i] = knew;
  int pi = parent_index(i);
  while(i >= 0 && h[i] > h[pi]) {
    swap(&h[i], &h[pi]);
    i = pi;
    pi = parent_index(i);
  }
}

int max_heap_maximum(int *h, int *heap_size) {
  return (*heap_size)? h[0]: -1;
}

int max_heap_extract_maximum(int *h, int *heap_size) {
  if(*heap_size <= 0)
    return -1;
  int max = max_heap_maximum(h, heap_size);
  h[0] = h[(*heap_size) - 1];
  (*heap_size)--;
  for(int i = (*heap_size)/2 - 1; i>=0; i--) {
    max_heapify(h, i, heap_size);
  }
  return max;
}

void max_heap_insert(int *h, int knew, int *heap_size) {
  if(*heap_size >= 100) {
    return;
  }
  h[(*heap_size)] = knew;
  (*heap_size)++;
  construct_max_heap(h, heap_size);
}

void construct_max_heap(int *h, int *heap_size) {
  for(int i = (*heap_size)/2-1; i>=0; i--) {
    max_heapify(h, i, heap_size);
  }
}

void construct_min_heap(int *h, int *heap_size) {
  for(int i = (*heap_size)/2-1; i>=0; i--) {
    min_heapify(h, i, heap_size);
  }
}

