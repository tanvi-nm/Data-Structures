#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    int priority;
    struct Node *next;
};

struct Node **Q;
int index = 0;

struct Node* createHead() {
    struct Node *F = (struct Node *)malloc(sizeof(struct Node));
    Q[index++] = F;
    return F;
}

void enqueue(struct Node *h, int value, int priority, int *F, int *R) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = val;
    newNode->link = NULL;

    if (rear != NULL) {
        rear->link = newNode;
    }
    rear = newNode;

    if (front == NULL) {
        front = newNode;
    }
}

int main() {

    struct Node *h0 = createHead();

}