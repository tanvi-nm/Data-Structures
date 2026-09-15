#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node *link;
};
struct Node *first = NULL;
struct Node *last = NULL;


void insertAtFirst(int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->info = val;

    if (first == NULL && last == NULL) {
        first = newNode;
        newNode->link = first;
        last = newNode;
        return;
    }

    newNode->link = first;
    first = newNode;
    last->link = newNode;
}


void insertAtLast(int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->info = val;

    if (first == NULL && last == NULL) {
        first = newNode;
        newNode->link = first;
        last = newNode;
        return;
    }

    last->link = newNode;
    newNode->link = first;
    last = newNode;
}


void display() {
    struct Node *save = first;
    while (save != last) {
        printf("%d, ", save->info);
        save = save->link;
    }
    printf("%d", save->info);
}

int count() {
    struct Node *save = first;
    int len = 0;
    while (save != last) {
        len++;
    }
    len += 1;

    return len;
}


int deleteAtPos(int pos) {

    int len = count();

    // edge case 1 : list is empty
    if (first == NULL) {
        printf("Cannot delete from empty list!");
        return -1;
    }

    // edge case 2 : invalid position is entered
    if (pos < 1 || pos > len) {
        printf("Invalid position entered!");
        return -1;
    }

    struct Node *save = first;
    int deletedValue = save->info;

    // edge case 3 : list contains only one element
    if (first == last) {
        free(save);
        first = NULL;
        last = NULL;
        return deletedValue;
    }

    // edge case 4 : first element is to be deleted
    if (pos == 1) {
        first = first->link;
        last->link = first;
        // free(save);
        return deletedValue;
    }

    int current = 1;
    struct Node *prev = NULL;

    while (current != pos) {
        prev = save;
        deletedValue = save->info;
        save = save->link;
        current++;
    }

    // edge case 5 : last element is to be deleted
    if (current == len) {
        prev->link = first;
        last = prev;
        last->link = first;
        free(save);
        return deletedValue;
    }

    prev->link = save->link;
    return deletedValue;

}

int main() {

    insertAtFirst(5);
    insertAtFirst(4);
    insertAtFirst(3);
    insertAtFirst(2);
    insertAtFirst(1);

    // printf("%d ", deleteAtPos(3));

    display();
    printf("\nHi");

    return 0;
}