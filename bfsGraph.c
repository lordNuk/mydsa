#include "graph.c"
#include "queue.c"

void reverseArray(int *, int); 

int bfsGraph (graph *g, int source, int target, int* path) {
  int l = g->length;

  if(target >= l || source >= l) 
    return 0;

  queue *q = qConstructor();
  int seen[l]; 
  int *prev = malloc(sizeof(int) * l);
  for (int i = 0; i<l; i++) {
    seen[i] = prev[i] = -1;
  }
  enqueue(q, source);
  seen[source] = 1;

  do {
    int curr = dequeue(q);
    if(curr == target)
      break;
    int *a = g->adjMatrix[curr];
    for(int i = 0; i < l; i++) {
      if(seen[i] == 1 || a[i] == 0)
        continue;
      enqueue(q, i);
      prev[i] = curr;
      seen[i] = 1;
    }
  } while(q->length > 0);

  if(prev[target] == -1) {
    return 0;
  }

  int p = target;
  int len = 0;
  while(p != source) {
    path[len] = p;
    p = prev[p];
    len++;
  }
  path[len++] = source;
  reverseArray(path, len);
  return len;
}

void reverseArray(int *a, int len) {
  int i = 0;
  for(i = 0; i<len/2; i++){
    int temp = a[i];
    a[i] = a[len-1-i];
    a[len-1-i] = temp;
  }
}

int main() {
  graph *g = graphConstructor();
  displayGraph(g);
  int i = 0, j = 0;
  printf("find path for target: ");
  printf("\nfrom: ");
  scanf("%d", &i);
  printf("to: ");
  scanf("%d", &j);
  int path[g->length];
  int len = bfsGraph(g, i, j, path);

  if(!len) {
    printf("no path found!\n");
  } else {
    printf("path: ");
  }
  for (i = 0; i < len; i++) {
    if(i == len-1)
      printf("%d", path[i]);
    else 
      printf("%d -> ", path[i]);
  }
  printf("\n");

  return 0;
}
