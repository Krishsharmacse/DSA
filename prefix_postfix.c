#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    int top;
    char items[MAX];
} Stack;

void initStack(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, char value) {
    stack->items[++(stack->top)] = value;
}

char pop(Stack* stack) {
    return stack->items[(stack->top)--];
}

char peek(Stack* stack) {
    return stack->items[stack->top];
}

int precedence(char operator) {
    if (operator == '+' || operator == '-') return 1;
    if (operator == '*' || operator == '/') return 2;
    return 0;
}

void infixToPostfix(char* infix, char* postfix) {
    Stack stack;
    initStack(&stack);
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        char current = infix[i];

        if (isalnum(current)) {
            postfix[j++] = current;
        }
        else if (current == '(') {
            push(&stack, current);
        }
        else if (current == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack);
        }
        else {
            while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(current)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, current);
        }
        i++;
    }

    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }
    postfix[j] = '\0';
}

int evaluatePostfix(char* postfix) {
    Stack stack;
    initStack(&stack);
    int i = 0;

    while (postfix[i] != '\0') {
        char current = postfix[i];

        if (isalnum(current)) {
            push(&stack, current - '0');
        }
        else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            int result;

            if (current == '+') result = operand1 + operand2;
            else if (current == '-') result = operand1 - operand2;
            else if (current == '*') result = operand1 * operand2;
            else if (current == '/') result = operand1 / operand2;

            push(&stack, result);
        }
        i++;
    }

    return pop(&stack);
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter an infix expression: ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = '\0';

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Evaluation result: %d\n", result);

    return 0;
}
