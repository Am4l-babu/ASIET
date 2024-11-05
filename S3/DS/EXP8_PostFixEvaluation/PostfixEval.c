#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef struct stack {
    double items[100];
    int top;
    int size;
} Stack;

int operator(char a) {
    if (a == '^') return 3;
    if (a == '*' || a == '/') return 2;
    if (a == '+' || a == '-') return 1;
    if (a == '(' || a == ')') return -1;
    return 0;
}

int isFull(Stack *s) {
    return s->top == s->size - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, double item) {
    if (isFull(s)) {
        printf("Error: Stack is full. Cannot push %lf\n", item);
    } else {
        s->items[++(s->top)] = item;
    }
}

double pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Error: Stack is empty. Cannot pop.\n");
        return 0;
    }
    return s->items[(s->top)--];
}

double peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Error: Stack is empty. Cannot peek.\n");
        return 0;
    }
    return s->items[s->top];
}

void convert(char infix[100], char postfix[100]) {
    int i = 0, j = 0;
    Stack s;
    s.size = 100;
    s.top = -1;

    while (infix[i]) {
        if (isdigit(infix[i])) {
            while (isdigit(infix[i])) {
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' ';
        } else if (infix[i] == '(') {
            push(&s, infix[i]);
            i++;
        } else if (infix[i] == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
                postfix[j++] = ' ';
            }
            pop(&s);
            i++;
        } else {
            while (!isEmpty(&s) && operator(infix[i]) <= operator(peek(&s))) {
                postfix[j++] = pop(&s);
                postfix[j++] = ' ';
            }
            push(&s, infix[i]);
            i++;
        }
    }

    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
        postfix[j++] = ' ';
    }
    postfix[j] = '\0';
}

double evaluate(char postfix[100]) {
    double p1, p2, r;
    int i = 0;
    Stack s;
    s.size = 100;
    s.top = -1;

    while (postfix[i]) {
        if (isdigit(postfix[i])) {
            char num[10];
            int j = 0;
            while (isdigit(postfix[i])) {
                num[j++] = postfix[i++];
            }
            num[j] = '\0';
            push(&s, atof(num));
        } else if (postfix[i] == ' ') {
            i++;
            continue;
        } else {
            p2 = pop(&s);
            p1 = pop(&s);
            if (postfix[i] == '+') r = p1 + p2;
            else if (postfix[i] == '-') r = p1 - p2;
            else if (postfix[i] == '*') r = p1 * p2;
            else if (postfix[i] == '/') r = p1 / p2;
            else if (postfix[i] == '^') r = pow(p1,p2);
            push(&s, r);
        }
        i++;
    }
    return pop(&s);
}

int main() {
    char infix[100], postfix[100];
    double result;
    int choice;
    while(1)
    { 
    printf("PostFix Evaluator\n 1.Enter an INFIX Expression \n 2.Enter a Postfix Expression \n 3.Exit");
    scanf("%d",&choice);
    switch(choice)
    {
    	case 1:{
    	printf("Enter the Infix Expression: ");
    	scanf("%s", infix);
    	convert(infix, postfix);
    	printf("The Postfix Expression is: %s\n", postfix);
    	result = evaluate(postfix);
    	printf("The result is %lf\n", result);
    	}
    	case 2:{
    	printf("Enter the postfix Expression: ");
    	scanf("%s", postfix);
    	result = evaluate(postfix);
    	printf("The result is %lf\n", result);
    	}
    	case 3:
    		return 0;
    }
    return 0;
}
}
