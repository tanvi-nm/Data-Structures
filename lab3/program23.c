#include <stdio.h>
#include <string.h>

int main() {
    int n;
    printf("Enter number of name : ");
    scanf("%d", &n);

    char names[n][100];

    for (int i=0; i<n; i++) {
        printf("Enter name %d : ", (i+1));
        scanf("%s", names[i]);
    }

    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if (strcmp(names[i], names[j]) > 0) {
                char temp[100];
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }

    for (int i=0; i<n; i++) {
        printf("%s, ", names[i]);
    }

    return 0;
}