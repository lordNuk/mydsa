#include "graph.c"
#include "queue.c"
#include <limits.h>

#define INF INT_MAX

int dijkstrasShortestPath(graph *g, int *path, int source, int sink);

int lowestUnvisited(int *seen, int *dists, int len) {
  int lowest = INF, idx = -1;
  for(int i = 0; i < len; i++) {
    if(seen[i])
      continue;
    if(dists[i] < lowest){
      lowest = dists[i];
      idx = i;
    }
  }
  return idx;
}
int hasUnvisited(int *seen, int *dists, int len) {
  for(int i = 0; i < len; i++) {
    if(seen[i])
      continue;
    if(dists[i] < INF)
      return i;
  }
  return -1;
}

void reverseArray(int *a, int len) {
  int i = 0;
  for(i = 0; i<len/2; i++){
    int temp = a[i];
    a[i] = a[len-1-i];
    a[len-1-i] = temp;
  }
}
int dijkstrasShortestPath(graph *g, int *path, int source, int sink) {
  int len = g->length, length = -1;
  if((source < 0 || source > len) || (sink < 0 || sink > len))
    return 0;
  int seen[len], prev[len], dists[len];
  for (int i = 0; i<len; i++) {
    seen[i] = 0;
    prev[i] = -1;
    dists[i] = INF;
  }
  dists[source] = 0;

  while(hasUnvisited(seen, dists, len) != -1) {
    int lo = lowestUnvisited(seen, dists, len);
    seen[lo] = 1;

    gList *list = g->adjList[lo];
    for(int i = 0; i<list->length; i++) {
      gListNode *curr = ALget(list, i); 
      if(seen[curr->to])
        continue;

      int dist = dists[lo] + curr->weight;
      if(dist < dists[curr->to]) {
        prev[curr->to] = lo;
        dists[curr->to] = dist;
      }
    }
  }
  while(prev[sink] != -1) {
    path[++length] = sink;
    sink = prev[sink];
  }

  path[++length] = source;

  reverseArray(path, ++length);
  return length;
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
  int len = dijkstrasShortestPath(g, path, i, j);
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

