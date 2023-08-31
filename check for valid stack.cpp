#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STACK_SIZE 100

struct Stack {
    char items[MAX_STACK_SIZE];
    int top;
};

// Function to initialize an empty stack
void initializeStack(struct Stack* stack) {
    stack->top = -1;
}

// Function to push an item onto the stack
void push(struct Stack* stack, char item) {
    if (stack->top == MAX_STACK_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->items[++stack->top] = item;
}

// Function to pop an item from the stack
char pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        return '\0';
    }
    return stack->items[stack->top--];
}

// Function to check if a sequence of parentheses is valid
bool isValidStack(char sequence[]) {
    struct Stack stack;
    initializeStack(&stack);

    int length = strlen(sequence);

    for (int i = 0; i < length; i++) {
        if (sequence[i] == '(' || sequence[i] == '{' || sequence[i] == '[') {
            push(&stack, sequence[i]);
        } else if (sequence[i] == ')' || sequence[i] == '}' || sequence[i] == ']') {
            if (stack.top == -1) {
                return false; // Stack is empty, but encountered a closing bracket
            }
            char popped = pop(&stack);
            if ((sequence[i] == ')' && popped != '(') ||
                (sequence[i] == '}' && popped != '{') ||
                (sequence[i] == ']' && popped != '[')) {
                return false; // Mismatched brackets
            }
        }
    }

    return stack.top == -1; // If the stack is empty, the sequence is valid
}

int main() {
    char sequence[] = "{[()]}";
    if (isValidStack(sequence)) {
        printf("The sequence is a valid stack.\n");
    } else {
        printf("The sequence is not a valid stack.\n");
    }

    return 0;
}
