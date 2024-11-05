#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int top;
    int size;
    int items[100];  
} Stack;

void initialize(Stack *s, int maxSize) {
    s->top = -1;
    if (maxSize < 100) {
        s->size = maxSize;
    } else {
        s->size = 100;
    }
}

int isFull(Stack *s) {
    if (s->top == s->size - 1) {
        return 1;
    } else {
        return 0;
    }
}

int isEmpty(Stack *s) {
    if (s->top == -1) {
        return 1;
    } else {
        return 0;
    }
}

void push(Stack *s, int item) {
    if (isFull(s)) {
        printf("Stack is full. Cannot push %d\n", item);
    } else {
        s->items[++(s->top)] = item;
        printf("Pushed %d onto the stack.\n", item);
    }
}

void pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot pop.\n");
    } else {
        printf("Popped %d from the stack.\n", s->items[(s->top)--]);
    }
}

void peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot peek.\n");
    } else {
        printf("Top item is %d.\n", s->items[s->top]);
    }
}

void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack contents:\n");
        for (int i = s->top; i >= 0; i--) {
            printf("%d\n", s->items[i]);
        }
    }
}

void clearConsole() {
    printf("\e[1;1H\e[2J");
}

void menu() {
    Stack s;
    int maxSize, choice, item;
    
    printf("Enter the maximum size of the stack (up to 100): ");
    scanf("%d", &maxSize);
    
    initialize(&s, maxSize);
    
    while (1) {
        printf("\nStack Menu:\n");
        printf("1. Initialize Stack\n");
        printf("2. Push\n");
        printf("3. Pop\n");
        printf("4. Peek\n");
        printf("5. Display Stack\n");
        printf("6. Clear Console\n");
        printf("7. Exit\n");
        
        printf("Enter your choice (1-7): ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            printf("Enter the new maximum size of the stack (up to 100): ");
            scanf("%d", &maxSize);
            initialize(&s, maxSize);
            printf("Stack has been initialized with size %d.\n", maxSize);
        } else if (choice == 2) {
            printf("Enter the item to push: ");
            scanf("%d", &item);
            push(&s, item);
        } else if (choice == 3) {
            pop(&s);
        } else if (choice == 4) {
            peek(&s);
        } else if (choice == 5) {
            display(&s);
        } else if (choice == 6) {
            clearConsole();
        } else if (choice == 7) {
            printf("Exiting the program.\n");
            exit(0);
        } else {
            printf("Invalid choice. Please choose a number between 1 and 7.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}
