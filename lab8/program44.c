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

void removeDuplicates() {
    struct Node *save = first;

    while (save->link != NULL) {
        if (save->info == (save->link)->info) {
            struct Node *temp = save->link;
            save->link = (save->link)->link;
            free(temp);
        }
        else {
            save = save->link;
        }
    }
}

int main() {

    insertAtFirst(5);
    insertAtFirst(5);
    insertAtFirst(5);
    insertAtFirst(4);
    insertAtFirst(3);
    insertAtFirst(3);
    insertAtFirst(3);
    insertAtFirst(2);
    insertAtFirst(1);
    insertAtFirst(1);

    removeDuplicates();

    display();
    
    return 0;

}