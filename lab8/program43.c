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

int checkSimilarity(struct Node **first1, struct Node **first2) {
    struct Node *save1 = *first1;
    struct Node *save2 = *first2;

    while (save1 && save2) {
        if (save1->info != save2->info) {
            break;
        }
        save1 = save1->link;
        save2 = save2->link;
    }

    if (!save1 && !save2) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {

    insertAtFirst(&first1, 5);
    insertAtFirst(&first1, 4);
    insertAtFirst(&first1, 3);
    insertAtFirst(&first1, 2);
    insertAtFirst(&first1, 1);


    insertAtFirst(&first2, 5);
    insertAtFirst(&first2, 4);
    insertAtFirst(&first2, 3);
    insertAtFirst(&first2, 2);
    insertAtFirst(&first2, 89);

    if (checkSimilarity(&first1, &first2)) {
        printf("Both the lists are equal");
    }
    else {
        printf("Both lists are not equal");
    }

    return 0;

}