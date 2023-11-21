#include "graph.c"
#include "queue.c"

int walk (graph *g, int curr, int target, int* path, int *plen, int* seen) {
  if (seen[curr]) {
    return 0;
  }
  seen[curr] = 1;
  path[(*plen)++] = curr;
  if (curr == target) {
    return 1;
  }
  gList *list = g->adjList[curr];
  for (int i = 0; i < list->length; i++) {
    gListNode *c = ALget(list, i); 
    int found = walk(g, c->to, target, path, plen, seen);
    if(found) {
      return 1;
    }
  }

  (*plen)--;
  return 0;
}
int dfsGraph (graph *g, int source, int target, int* path) {
  int seen[g->length], len = 0;
  for (int i = 0; i < g->length; i++) {
    seen[i] = 0;
  }
  if (walk(g, source, target, path, &len, seen))
      return len;
  return 0;
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
  int gl = g->length;
  int path[gl];
  int len = dfsGraph(g, i, j, path);
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
