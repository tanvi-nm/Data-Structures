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

void swapNodes(int k) {

    int n = count();

    // edge case 1: n is odd and k is the middle node (swap with itself)
    if (n % 2 != 0 && k == (n/2 + 1)) {
        return;
    }

    struct Node *p1 = NULL, *c1 = first, *n1 = first->link;
    struct Node *p2 = NULL, *c2 = first, *n2 = first->link, *temp;

    // find kth node from start
    int current = 1;
    while (current != k) {
        p1 = c1;
        c1 = n1;
        n1 = n1->link;
        current++;
    }

    // find kth node from end (using slow & fast + k step delay)
    temp = c1;
    while (temp->link != NULL) {
        p2 = c2;
        c2 = c2->link;
        n2 = n2->link;
        temp = temp->link;
    }

    // edge case 2: swapping the ends
    if (k == 1 || k == n) {
        p2->link = c1;
        c2->link = n1;
        c1->link = NULL;
        first = c2;
    }

    // edge case 3.1 : swapping adjacent nodes with c1 before c2
    else if (c2 == c1->link) {
        p1->link = c2;
        c2->link = c1;
        c1->link = n2;
    }

    // edge case 3.2 : swapping adjacent nodes with c2 before c1
    else if (c1 == c2->link) {
        p2->link = c1;
        c1->link = c2;
        c2->link = n1;
    }

    // normal case
    else {
        p1->link = c2;
        c1->link = n2;
        p2->link = c1;
        c2->link = n1;
    }
}

int main() {

    insertAtFirst(9);
    insertAtFirst(8);
    insertAtFirst(7);
    insertAtFirst(6);
    insertAtFirst(5);
    insertAtFirst(4);
    insertAtFirst(3);
    insertAtFirst(2);
    insertAtFirst(1);

    int k = 3;

    printf("List before swapping : ");
    display();
    printf("\n");

    swapNodes(k);

    printf("List after swapping : ");
    display();

    return 0;

}