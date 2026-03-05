/*Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push into stack
void push(char x) {
    stack[++top] = x;
}

// Pop from stack
char pop() {
    if (top == -1)
        return -1;
    return stack[top--];
}

// Return precedence
int precedence(char x) {
    if (x == '^')
        return 3;
    else if (x == '*' || x == '/')
        return 2;
    else if (x == '+' || x == '-')
        return 1;
    else
        return 0;
}

int main() {
    char exp[MAX];
    char result[MAX];
    int i, j = 0;

    scanf("%s", exp);

    for (i = 0; exp[i] != '\0'; i++) {

        // If operand, add to output
        if (isalnum(exp[i])) {
            result[j++] = exp[i];
        }

        // If opening bracket
        else if (exp[i] == '(') {
            push(exp[i]);
        }

        // If closing bracket
        else if (exp[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                result[j++] = pop();
            }
            pop(); // remove '('
        }

        // Operator
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(exp[i])) {
                result[j++] = pop();
            }
            push(exp[i]);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        result[j++] = pop();
    }

    result[j] = '\0';

    printf("%s\n", result);

    return 0;
}