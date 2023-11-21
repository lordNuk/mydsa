/* infix order of operation:
 * 1. parentheses
 * 2. exponents (right to left)
 * 3. multiplication and division (left to right)
 * 4. addition and subtraction (left to right)
 */

/* Prefix(polish notation) order of operation:
 * 1. find opr 
 * 2. perform opr on next 2 operands
 * 3. push it to stack
 * 4. 
 */


/* Postfix(reverse polish notation) order of operation:
 * 1. find opr 
 * 2. perform opr on next 2 operands
 * 3. push it to stack
 */

/* Evaluation of prefix and postfix exp
 * 
 */

int isOperand(char c) {
    return (c >= 'a' && c <= 'z');
}

int hasLowerPrecedence(char a, char b) {
    switch (b) {
        case '+':
        case '-': {
                      if(a == '*' || a == '/' || a == '^') {
                          return 0;
                      }
                  } break;
        case '*':
        case '/': {
                      if(a == '^') {
                          return 0;
                      }
                  } break;
    }
    return 1;
}

char * infixToPostfix(char *str) {
    int n = strlen(str);
    char *temp = malloc(sizeof(char)*n);
    struct stack *operators = sConstructor();

    int i = 0, j = 0;
    while(str[i]) {
        if(isOperand(str[i])) {
            temp[j] = str[i];
            j++;
        } else {
            while(!isEmpty(operators)) {
                if(str[i] == ')') {
                    char v = stackPop(operators);
                    while (v != '(') {
                        temp[j] = v;
                        v = stackPop(operators);
                        j++;
                    }
                    break;
                }
                char v = stackPop(operators);
                if(hasLowerPrecedence(v, str[i])) {
                    stackPush(operators, v);
                    break;
                } 
                temp[j] = v;
                j++;
            }
            if(str[i] != ')') {
                stackPush(operators, str[i]);
            }
        }
        i++;
    }
    while(!isEmpty(operators)) {
        temp[j] = stackPop(operators);
        j++;
    }
    return temp;
}
