#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node *link;
};

struct Node *first1 = NULL;
struct Node *first2 = NULL;

void insertAtFirst(struct Node **first, int x) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->info = x;
    newNode->link = *first;
    *first = newNode;
}

void display(struct Node **first) {
    struct Node *save = *first;
    while (save) {
        printf("%d, ", save->info);
        save = save->link;
    }
    free(save);
}

int count(struct Node **first) {
    struct Node *save = *first;
    int n = 0;
    while (save) {
        n++;
        save = save->link;
    }
    return n;
}

void copyList(struct Node **first1, struct Node **first2) {

    if (first1 == NULL) {
        return;
    }

    insertAtFirst(first2, (*first1)->info);

    struct Node *save1 = (*first1)->link;
    struct Node *save2 = *first2;

    while (save1) {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->info = save1->info;
        save2->link = newNode;
        newNode->link = NULL;
        save1 = save1->link;
        save2 = save2->link;
    }

}
int main() {

    insertAtFirst(&first1, 5);
    insertAtFirst(&first1, 4);
    insertAtFirst(&first1, 3);
    insertAtFirst(&first1, 2);
    insertAtFirst(&first1, 1);

    copyList(&first1, &first2);

    display(&first2);

    return 0;

}