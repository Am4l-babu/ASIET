#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
    int size;
} Stack;

void initialize(Stack *s) {
    s->top = NULL;
    s->size = 0;
}

int isFull(Stack *s) {
    return 0;  
}

int isEmpty(Stack *s) {
    return s->top == NULL;
}

void push(Stack *s, int item) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed. Cannot push %d\n", item);
        return;
    }
    newNode->data = item;
    newNode->next = s->top;
    s->top = newNode;
    s->size++;
    printf("Pushed %d onto the stack.\n", item);
}

void pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot pop.\n");
    } else {
        Node *temp = s->top;
        printf("Popped %d from the stack.\n", temp->data);
        s->top = s->top->next;
        free(temp);
        s->size--;
    }
}

void peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot peek.\n");
    } else {
        printf("Top item is %d.\n", s->top->data);
    }
}

void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
    } else {
        Node *current = s->top;
        printf("Stack contents:\n");
        while (current != NULL) {
            printf("%d\n", current->data);
            current = current->next;
        }
    }
}

void clearConsole() {
    printf("\e[1;1H\e[2J");
}

void menu() {
    Stack s;
    int choice, item;
    
    initialize(&s);
    
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
            initialize(&s);
            printf("Stack has been initialized.\n");
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
