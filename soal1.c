#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char id[20];
    int duration;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    int size;
} Queue;

void initQueue(Queue *q) {
    q->head = q->tail = NULL;
    q->size = 0;
}

void enqueue(Queue *q, char *id, int duration) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->id, id);
    newNode->duration = duration;
    newNode->next = NULL;

    if (q->tail == NULL) {
        q->head = q->tail = newNode;
    } else {
        q->tail->next = newNode;
        q->tail = newNode;
    }
    q->size++;
}

int main() {
    int n;
    scanf("%d", &n);

    Queue q;
    initQueue(&q);

    for (int i = 0; i < n; i++) {
        char id[20];
        int duration;
        scanf("%s %d", id, &duration);
        enqueue(&q, id, duration);
    }

    printf("ORDER");
    Node *cur = q.head;
    while (cur != NULL) {
        printf(" %s", cur->id);
        cur = cur->next;
    }
    printf("\n");

    int totalWait = 0;
    int waitSoFar = 0;
    cur = q.head;
    while (cur != NULL) {
        totalWait += waitSoFar;
        waitSoFar += cur->duration;
        cur = cur->next;
    }

    printf("WAIT %d\n", totalWait);

    cur = q.head;
    while (cur != NULL) {
        Node *temp = cur;
        cur = cur->next;
        free(temp);
    }

    return 0;
}

