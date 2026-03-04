/*Problem: Implement push and pop operations on a stack and verify stack operations.

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)

Output:
- Print remaining stack elements from top to bottom

Example:
Input:
5
10 20 30 40 50
2

Output:
30 20 10*/

#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push operation
void push(int value){
    if(top == MAX-1){
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = value;
}

// Pop operation
void pop(){
    if(top == -1){
        printf("Stack Underflow\n");
        return;
    }
    top--;
}

// Display stack from top to bottom
void display(){
    for(int i = top; i >= 0; i--){
        printf("%d ", stack[i]);
    }
}

int main(){
    int n, m, x;

    // number of elements to push
    scanf("%d", &n);

    // push elements
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        push(x);
    }

    // number of pops
    scanf("%d", &m);

    for(int i = 0; i < m; i++){
        pop();
    }

    // print remaining stack
    display();

    return 0;
}