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

void sort() {
    struct Node *end = NULL;
    struct Node *p, *c, *n;

    while (end != first) {
        p = NULL;
        c = first;
        n = first->link;
        while (c->link != end) {
            if (c->info <= n->info) {
                p = c;
                c = n;
                n = n->link;
            }
            else if (c == first) {
                c->link = n->link;
                n->link = c;
                first = n;
                p = first;
                n = c->link;
            }
            else {
                p->link = n;
                c->link = n->link;
                n->link = c;
                p = n;
                n = c->link;
            }
        }
        end = c;
    }
}

int main() {

    insertAtFirst(-1);
    insertAtFirst(2);
    insertAtFirst(4);
    insertAtFirst(7);
    insertAtFirst(99);
    insertAtFirst(122);
    insertAtFirst(2);

    printf("List before sorting : ");
    display();

    printf("\n\n");

    sort();

    printf("List after sorting : ");
    display();

   return 0;
}