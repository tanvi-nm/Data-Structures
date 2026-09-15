#include <stdio.h>
#include <stdlib.h>

struct Student {
    int rollNo;
    char name[50];
    char branch[30];
    int batchNo;
};


int main() {

    struct Student *s1 = (struct Student *)malloc(sizeof(struct Student));
    
    printf("Enter roll number : ");
    scanf("%d", &s1->rollNo);
    printf("Enter name : ");
    scanf("%s", s1->name);
    printf("Enter branch name : ");
    scanf("%s", s1->branch);
    printf("Enter branch number : ");
    scanf("%d", &s1->batchNo);

    printf("Roll Number : %d\nName : %s\nBranch ; %s\nBatch Number : %d", s1->rollNo, s1->name, s1->branch, s1->batchNo);

    return 0;
}