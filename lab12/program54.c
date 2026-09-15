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

void insertAtLast(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->info = value;
    newNode->rptr = NULL;

    if (first == NULL) {
        newNode->lptr = NULL;
        first = newNode;
        return;
    }

    struct Node *save = first;
    while (save->rptr != NULL) {
        save = save->rptr;
    }

    save->rptr = newNode;
    newNode->lptr = save;
}

int deleteAtPos(int pos) {
    if (first == NULL || pos < 1) {
        printf("Deletion failed!\n");
        return -1;
    }

    struct Node *prev = NULL;
    struct Node *current = first;
    int deletedValue = -1;
    int currentPos = 1;

    if (pos == 1) {
        first = first->rptr;
        first->lptr = NULL;
        deletedValue = current->info;
        free(current);
        return deletedValue;
    }

    while (current != NULL && currentPos != pos) {
        prev = current;
        current = current->rptr;
        currentPos++;
    }

    if (current == NULL) {
        printf("Deletion failed!\n");
        return -1;
    }
    else {
        prev->rptr = current->rptr;
        if (current->rptr != NULL) {
            (current->rptr)->lptr = prev;
            deletedValue = current->info;
        }
        free(current);
        return deletedValue;
    }

}

int main() {

    int choice = 1;

    while (choice != 0) {
        printf("\n0 Exit\n");
        printf("1 Insert at first\n");
        printf("2 Insert at last\n");
        printf("3 Display list\n");
        printf("4 Delete at position\n");

        printf("\n Enter your choice : ");
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        }

        else if (choice == 1) {
            int value;
            printf("Enter value to be inserted : ");
            scanf("%d", &value);
            insertAtFirst(value);
        }

        else if (choice == 2) {
            int value;
            printf("Enter value to be inserted : ");
            scanf("%d", &value);
            insertAtLast(value);
        }

        else if (choice == 3) {
            display();
        }

        else if (choice == 4) {
            int pos;
            printf("Enter position to delete at : ");
            scanf("%d", &pos);
            int result = deleteAtPos(pos);
            if (result != -1) {
                printf("Deleted element : %d", result);
            }
        }

        else {
            printf("Invalid choice!");
        }
    }
}