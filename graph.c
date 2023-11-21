#include <stdlib.h>
#include <stdio.h>
#include "adjListGraph.c"

struct graph {
 int *val;
 int length;
 int **adjMatrix;
 gList **adjList;
};

typedef struct graph graph;

void createAdjMatrix (graph *g);
void createAdjList (graph *g);

graph * graphConstructor () {
  graph *g = malloc(sizeof(graph));

// printf("enter length of graph: \t");
// scanf("%d", &g->length);
  g->length = 5;
  g->val = malloc(sizeof(int)*g->length);

// printf("enter values of graph vertices: ");
// for (int i = 0; i < g->length; i++) {
//   scanf("%d", &g->val[i]);
// }

 for (int i = 0; i < g->length; i++) {
   g->val[i] = i;
 }
  createAdjMatrix(g);
  createAdjList(g);
  return g;
}

void createAdjMatrix (graph *g) {
  int i = g->length;
  int c, w, x, y;
  g->adjMatrix = malloc(sizeof(int*) * i);
  for (x = 0; x < i; x++)
    g->adjMatrix[x] = malloc(sizeof(int)*i);
 for (x = 0; x < i; x++) {
   for (y = 0; y < i; y++) {
//     if(x == y) {
       g->adjMatrix[x][y] = 0;
//      continue;
//    }
//    printf("is %d -> %d?(0, weight>0): \t\t", g->val[x], g->val[y]);
//    scanf("%d", &c);
//    g->adjMatrix[x][y] =  c;
   }
 }
 //printf("graph input complete\n");
  g->adjMatrix[0][1] = 1;
  g->adjMatrix[0][2] = 4;
  g->adjMatrix[1][0] = 1;
  g->adjMatrix[2][3] = 2;
  g->adjMatrix[3][4] = 5;
}

void createAdjList (graph *g) {
  g->adjList = malloc(sizeof(gList*) * g->length); 
  int i;
  for (i = 0; i < g->length; i++)
    g->adjList[i] = adjListConstructor();

   ALenqueue(g->adjList[0], 1, 1); 
   ALenqueue(g->adjList[0], 2, 4); 
   ALenqueue(g->adjList[1], 0, 1); 
   ALenqueue(g->adjList[2], 3, 2); 
   ALenqueue(g->adjList[3], 4, 5); 
}

void displayGraph (graph *g) {
  int i = g->length;
  for (int x = 0; x < i; x++) {
    for (int y = 0; y < i; y++) {
      if(g->adjMatrix[x][y] != 0) {
        printf("%d --(%d)--> %d\t\t", g->val[x], g->adjMatrix[x][y], g->val[y]);
      }
    }
    printf("\n");
  }
  printf("adjList: \n");
  for (int x = 0; x < i; x++) {
    for(int y = 0; y < g->adjList[x]->length; y++) {
      gListNode *temp = ALget(g->adjList[x], y);
      printf("%d --(%d)--> %d\t\t", g->val[x], temp->weight, temp->to);
    }
    printf("\n");
  }
}

