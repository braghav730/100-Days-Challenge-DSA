/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// Push function
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Pop function
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }

    struct Node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);

    return val;
}

// Evaluate postfix expression
int evaluatePostfix(char exp[]) {
    int i = 0;

    while (exp[i] != '\0') {

        if (exp[i] == ' ') {
            i++;
            continue;
        }

        // Check digit manually
        if (exp[i] >= '0' && exp[i] <= '9') {
            push(exp[i] - '0');
        }

        else {
            int val2 = pop();
            int val1 = pop();

            switch (exp[i]) {
                case '+':
                    push(val1 + val2);
                    break;

                case '-':
                    push(val1 - val2);
                    break;

                case '*':
                    push(val1 * val2);
                    break;

                case '/':
                    push(val1 / val2);
                    break;
            }
        }

        i++;
    }

    return pop();
}

// Main function
int main() {
    char exp[100];

    printf("Enter postfix expression: ");
    fgets(exp, sizeof(exp), stdin);

    printf("Result = %d\n", evaluatePostfix(exp));

    return 0;
}