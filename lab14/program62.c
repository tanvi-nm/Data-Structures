#include <stdio.h>
#include <stdlib.h>

#define MAX 100
int TOP = -1;
char STACK[MAX];

int push(char ch) {
    if (TOP >= MAX - 1) {
        printf("Stack overflow!");
        return 0;
    }
    else {
        STACK[++TOP] = ch;
        return 1;
    }
}

char pop() {
    if (TOP < 0) {
        printf("Stack underflow!");
        return '\0';
    }
    else {
        return STACK[TOP--];
    }
}

char * removeStars(char * s) {
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] != '*') {
            push(s[i]);
        }
        else {
            pop();
        }
        i++;
    }

    char *ans = (char *)malloc(100);

    int j = 0;
    while (TOP >= 0) {
        ans[j++] = pop();
    }

    for (i = 0; i < j/2; i++) {
        char temp = ans[i];
        ans[i] = ans[j-i-1];
        ans[j-i-1] = temp;
    }
    return ans;
}

int main() {
    char s[100];
    printf("Enter a string : ");
    scanf("%s", s);

    printf("String after removing stars : %s", removeStars(s));

    return 0;
}