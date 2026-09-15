#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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


int deleteFirst() {

    if (first == NULL) {
        printf("Cannot delete from empty list! ");
        return -1;
    }
    struct Node *save = first;
    int deletedValue = save->info;
    first = first->link;
    free(save);
    return deletedValue;
}


void insertAtEnd(int x) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->info = x;
    newNode->link = NULL;

    if (first == NULL) {
        first = newNode;
        return;
    }

    struct Node *save = first;
    while (save->link != NULL) {
        save = save->link;
    }
    save->link = newNode;
}


int deleteLast() {
    if (first == NULL) {
        printf("Cannot delete from an empty list!");
        return -1;
    }

    struct Node *save = first, *prev = NULL;
    while (save->link != NULL) {
        prev = save;
        save = save->link;
    }

    int deletedValue = save->info;
    prev->link = NULL;

    free(save);

    return deletedValue;
}

int deleteAtPosition(int pos) {
    int n = count();
    if (pos < 1 || pos > n) return INT_MIN;

    if (pos == 1) {
        return deleteFirst();
    }
    else if (pos == n) {
        return deleteLast();
    }

    struct Node *save = first;
    int current = 1;
    while (current != (pos - 1)) {
        save = save->link;
    }
    int deletedValue = (save->link)->info;

    save->link = (save->link)->link;
    free(save->link);

    return deletedValue;
}


int main() {

    int choice = 1;

    while (choice) {
        printf("0. Exit\n");
        printf("1. Insert at first\n");
        printf("2. Insert at last\n");
        printf("3. Display list\n");
        printf("4. Count number of nodes\n");
        printf("5. Delete first node\n");
        printf("6. Delete last node\n");
        printf("7. Delete at specific position\n");

        printf("Enter your choice : ");
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        }

        else if (choice == 1) {
            int value;
            printf("Enter value to be inserted : ");
            scanf("%d", &value);

            insertAtFirst(value);
            display();
        }

        else if (choice == 2) {
            int value;
            printf("Enter value to be inserted : ");
            scanf("%d", &value);

            insertAtEnd(value);
            display();
        }

        else if (choice == 3) {
            display();
        }

        else if (choice == 4) {
            int n = count();
            printf("The number of nodes in the list are : %d", n);
        }

        else if (choice == 5) {
            printf("The value deleted : %d", deleteFirst());
        }

        else if (choice == 6) {
            printf("The value deleted : %d", deleteLast());
        }

        else if (choice == 7) {
            int pos;
            printf("Enter position to be deleted at : ");
            scanf("%d", &pos);

            printf("The value deleted is : %d", deleteAtPosition(pos));
        }

        printf("\n");
    }

    return 0;
}