#include <stdio.h>
#include <string.h>

typedef struct stack {
    char items[100];
    int top;
    int size;
} Stack;

int operator(char a) {
    if (a == '^') return 3;
    if (a == '*' || a == '/') return 2;
    if (a == '+' || a == '-') return 1;
    if(a=='('||a==')')return -1;
    return 0;
}

int isFull(Stack *s) {
    return s->top == s->size - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char item) {
    if (isFull(s)) {
        printf("Error: Stack is full. Cannot push %c\n", item);
    } else {
        s->items[++(s->top)] = item;
    }
}

char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Error: Stack is empty. Cannot pop.\n");
        return '\0';
    }
    return s->items[(s->top)--];
}

char peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Error: Stack is empty. Cannot peek.\n");
        return '\0';
    }
    return s->items[s->top];
}

void convert(char infix[100], char postfix[100]) {
    int i = 0, j = 0;
    Stack s;
    s.size = 100;
    s.top = -1;

    while (infix[i]) {
        if (operator(infix[i])==0) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(&s, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s);
        } else {
            while (!isEmpty(&s) && operator(infix[i]) <= operator(peek(&s))) {
                postfix[j++] = pop(&s);
            }
            push(&s, infix[i]);
        }
        i++;
    }

    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
    
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}

int main() {
    char infix[100], postfix[100];
    printf("Enter the Infix Expression: ");
    scanf("%s", infix);
    convert(infix, postfix);
    printf("The Postfix Expression is: %s\n", postfix);
    return 0;
}
