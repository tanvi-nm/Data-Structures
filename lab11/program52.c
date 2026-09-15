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
        last = newNode;
        newNode->link = first;
        return;
    }

    newNode->link = first;
    first = newNode;
    last->link = first;
}

void display(struct Node *first, struct Node *last) {
    struct Node *save = first;
    while (save != last) {
        printf("%d, ", save->info);
        save = save->link;
    }
    printf("%d\n", save->info);
}

void splitList(struct Node **first, struct Node **last) {
    struct Node *slow = *first;
    struct Node *fast = *first;

    while (fast->link != *last && fast != *last) {
        fast = (fast->link)->link;
        slow = slow->link;
    }

    struct Node *head1 = *first;
    struct Node *head2 = slow->link;

    struct Node *end1 = slow;
    struct Node *end2 = *last;

    end1->link = head1;
    end2->link = head2;

    display(head1, end1);
    display(head2, end2);
    
}

int main() {

    // insertAtFirst(6);
    insertAtFirst(5);
    insertAtFirst(4);
    insertAtFirst(3);
    insertAtFirst(2);
    insertAtFirst(1);

    splitList(&first, &last);

    return 0;
}