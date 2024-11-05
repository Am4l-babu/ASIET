#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjLists;
} Graph;

typedef struct Queue {
    int items[100];
    int front;
    int rear;
} Queue;

Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(Node*));
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void removeEdge(Graph* graph, int src, int dest) {
    Node* temp = graph->adjLists[src];
    Node* prev = NULL;

    while (temp && temp->vertex != dest) {
        prev = temp;
        temp = temp->next;
    }

    if (temp) {
        if (prev) {
            prev->next = temp->next;
        }
        else {
            graph->adjLists[src] = temp->next;
        }
        free(temp);
    }

    temp = graph->adjLists[dest];
    prev = NULL;

    while (temp && temp->vertex != src) {
        prev = temp;
        temp = temp->next;
    }

    if (temp) {
        if (prev) {
            prev->next = temp->next;
        }
        else {
            graph->adjLists[dest] = temp->next;
        }
        free(temp);
    }
}

Queue* createQueue() {
    Queue* q = malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(Queue* q) {
    return q->rear == -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == 99) {
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(Queue* q) {
    int item;
    if (isEmpty(q)) {
        return -1;
    }
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return item;
}

void bfs(Graph* graph, int startVertex) {
    int visited[100] = { 0 };
    Queue* q = createQueue();

    visited[startVertex] = 1;
    enqueue(q, startVertex);

    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        Node* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
}

void dfsUtil(Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    Node* temp = graph->adjLists[vertex];
    while (temp) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex]) {
            dfsUtil(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

void dfs(Graph* graph, int startVertex) {
    int visited[100] = { 0 };
    dfsUtil(graph, startVertex, visited);
}

void displayMenu() {
    printf("Menu:\n");
    printf("1. Add Edge\n");
    printf("2. Remove Edge\n");
    printf("3. BFS Traversal\n");
    printf("4. DFS Traversal\n");
    printf("5. Exit\n");
}

int main() {
    int vertices = 100;
    Graph* graph = createGraph(vertices);
    int choice, src, dest, startVertex;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter source and destination vertices (e.g., 0 1): ");
            scanf("%d %d", &src, &dest);
            addEdge(graph, src, dest);
            break;
        case 2:
            printf("Enter source and destination vertices to remove (e.g., 0 1): ");
            scanf("%d %d", &src, &dest);
            removeEdge(graph, src, dest);
            break;
        case 3:
            printf("Enter starting vertex for BFS: ");
            scanf("%d", &startVertex);
            printf("BFS Traversal starting from vertex %d:\n", startVertex);
            bfs(graph, startVertex);
            printf("\n");
            break;
        case 4:
            printf("Enter starting vertex for DFS: ");
            scanf("%d", &startVertex);
            printf("DFS Traversal starting from vertex %d:\n", startVertex);
            dfs(graph, startVertex);
            printf("\n");
            break;
        case 5:
            free(graph->adjLists);
            free(graph);
            exit(0);
        default:
            printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
