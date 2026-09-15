#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char *str, int start, int end) {
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main() {

    char *str = (char *)malloc(50 * sizeof(char));
    char *rev = (char *)malloc(50 * sizeof(char));

    printf("Enter a string : ");
    scanf("%s", str);

    int n = strlen(str);

    for (int i = 0; i < n; i++) {
        rev[i] = str[i];
    }

    reverse(rev, 0, n-1);
    
    if (strcmp(str, rev) == 0) {
        printf("%s is a palindomic string", str);
    }
    else {
        printf("%s is not a palindomic string", str);
    }

    return 0;
}