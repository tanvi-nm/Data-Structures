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

int gcd(int num1, int num2) {
    int min = (num1 < num2) ? num1 : num2;
    int val = 1;
    for (int i = 1; i <= min; i++) {
        if ((num1 % i == 0) && (num2 % i == 0)) {
            val = i;
        }
    }
    return val;
}

void addGCD() {
    if (first == NULL || first->link == NULL) {
        return;
    }

    struct Node *p = first;
    struct Node *q = first->link;

    while (q != NULL) {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->info = gcd(p->info, q->info);

        p->link = newNode;
        newNode->link = q;

        p = q;
        q = q->link;
    }
}


int main() {

    insertAtFirst(3);
    insertAtFirst(10);
    insertAtFirst(6);
    insertAtFirst(18);

    printf("List before adding GCDs : ");
    display();
    printf("\n");

    addGCD();

    printf("List after adding GCDs : ");
    display();

    return 0;

}