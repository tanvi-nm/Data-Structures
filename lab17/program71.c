#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node *link;
};

struct Node *front, *rear;

void enqueue(int val) {
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

int dequeue() {
    if (front == NULL) {
        printf("Queue underflow!");
        return -1;
    }
    int deletedValue = front->info;
    struct Node *temp = front;
    if (front == rear) {
        front = NULL;
        rear = NULL;
    }
    else {
        front = front->link;
    }
    free(temp);
    return deletedValue;
}

void display() {
    if (front == NULL) {
        printf("Queue is empty!");
        return;
    }
    struct Node *temp = front;
    while (temp != rear) {
        printf("%d ", temp->info);
        temp = temp->link;
    }
    printf("%d\n", temp->info);
}

int main() {
    enqueue(1);
    display();
    enqueue(2);
    display();
    enqueue(3);
    display();
    enqueue(4);
    display();

    dequeue();
    display();
    dequeue();
    display();

    enqueue(5);
    display();

    return 0;
}