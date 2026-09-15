#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node *link;
};

struct Node *poly1 = NULL;
struct Node *poly2 = NULL;

void insertAtFirst(struct Node **poly, int c, int e) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->link = *poly;
    *poly = newNode;
}

void display(struct Node *poly) {
    struct Node *save = poly;
    while (save != NULL) {
        if (save->coeff != 0) {
            if (save->exp != 0) {
                printf(" %dx^%d ", save->coeff, save->exp);
            }
            else {
                printf(" %d ", save->coeff);
            }
        }
        save = save->link;
    }
}

struct Node * addPolynomials() {
    struct Node *p1 = poly1;
    struct Node *p2 = poly2;

    struct Node *ans = (struct Node *)malloc(sizeof(struct Node));
    struct Node *prev = ans;

    if (p1->exp == p2->exp) {
        ans->coeff = p1->coeff + p2->coeff;
        ans->exp = p1->exp;
        p1 = p1->link;
        p2 = p2->link;
    }
    else if (p1->exp > p2->exp) {
        ans->coeff = p1->coeff;
        ans->exp = p1->exp;
        p1 = p1->link;
    }
    else {
        ans->coeff = p2->coeff;
        ans->exp = p2->exp;
        p2 = p2->link;
    }

    while (p1 != NULL && p2 != NULL) {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        if (p1->exp == p2->exp) {
            newNode->coeff = p1->coeff + p2->coeff;
            newNode->exp = p1->exp;
            p1 = p1->link;
            p2 = p2->link;
        }
        else if (p1->exp > p2->exp) {
            newNode->coeff = p1->coeff;
            newNode->exp = p1->exp;
            p1 = p1->link;
        }
        else {
            newNode->coeff = p2->coeff;
            newNode->exp = p2->exp;
            p2 = p2->link;
        }
        prev->link = newNode;
        prev = newNode;
    }
    prev->link = NULL;

    return ans;
}

int main() {
    
    insertAtFirst(&poly1, 2, 0);
    insertAtFirst(&poly1, 5, 1);
    insertAtFirst(&poly1, 3, 2);

    insertAtFirst(&poly2, 9, 0);
    insertAtFirst(&poly2, 3, 1);
    insertAtFirst(&poly2, 7, 2);

    // display(poly1);
    // printf("\n");
    // display(poly2);

    struct Node *add = addPolynomials();
    display(add);

    return 0;
}