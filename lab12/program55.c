#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *lptr;
    int info;
    struct Node *rptr;
};

struct Node *first = NULL;

void insertAtFirst(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->info = value;
    newNode->lptr = NULL;
    newNode->rptr = first;
    first = newNode;
}

void display() {
    struct Node *save = first;

    while (save != NULL) {
        printf("%d, ", save->info);
        save = save->rptr;
    }
}

void deleteAlternate() {
    if (first == NULL || first->rptr == NULL) {
        return;
    }

    struct Node *current = first;
    struct Node *next = first->rptr;

    while (next != NULL && next->rptr != NULL) {
        struct Node *temp = next;
        current->rptr = next->rptr;
        (next->rptr)->lptr = current;
        current = current->rptr;
        next = current->rptr;
        free(temp);
    }
    free(next);
    current->rptr = NULL;

}

int main() {
    insertAtFirst(8);
    insertAtFirst(7);
    insertAtFirst(6);
    insertAtFirst(5);
    insertAtFirst(4);
    insertAtFirst(3);
    insertAtFirst(2);
    insertAtFirst(1);

    deleteAlternate();

    display();

    return 0;
}