#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "stack.c"
#include "infix.c"

int main() {
    char *str = "a*(b+c)";
    char *pos = infixToPostfix(str);
    printf("postfix exp: %s\n", pos);
    return 0;
}









