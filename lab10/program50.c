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

void swapAdjacent() {
    if (first == NULL || first->link == NULL) {
        return;
    }

    struct Node *p = NULL, *c = first, *n = first->link;

    c->link = n->link;
    n->link = c;
    first = n;

    p = c;
    c = c->link;

    while (c != NULL && c->link != NULL) {
        n = c->link;

        p->link = n;
        c->link = n->link;
        n->link = c;

        p = c;
        c = c->link;
    }

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

    printf("List before swapping : ");
    display();
    printf("\n");

    swapAdjacent();

    printf("List after swapping : ");
    display();

    return 0;
}