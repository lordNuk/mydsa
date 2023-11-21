#include<stdlib.h>
#include<time.h>

int getRandom(int a, int b) {
  srand(time(0));
  return (rand() % (b-a)) + a;
}
