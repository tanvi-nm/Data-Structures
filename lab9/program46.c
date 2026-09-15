#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node *link;
};

struct Node *first = NULL;

void insertAtFirst(int x) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->info = x;
    newNode->link = first;
    first = newNode;
}

void display() {
    struct Node *save = first;
    while (save) {
        printf("%d, ", save->info);
        save = save->link;
    }
    free(save);
}

int count() {
    struct Node *save = first;
    int n = 0;
    while (save) {
        n++;
        save = save->link;
    }
    return n;
}

void reverse() {
    if (first == NULL || first->link == NULL) {
        return;
    }

    struct Node *prev = NULL;
    struct Node *current = first;
    struct Node *next = first->link;

    while (next != NULL) {
        current->link = prev;
        prev = current;
        current = next;
        next = next->link;
    }

    current->link = prev;
    first = current;
}

int main() {

    insertAtFirst(1);
    insertAtFirst(2);
    insertAtFirst(3);
    insertAtFirst(4);
    insertAtFirst(5);

    reverse();

    display();

    return 0;
}