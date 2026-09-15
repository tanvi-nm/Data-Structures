#include <stdio.h>

#define MAX 100
int TOP = -1;
char STACK[MAX];

void push(char ch) {
    if (TOP >= MAX-1) {
        printf("Stack overflow!");
    }
    else {
        STACK[++TOP] = ch;
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

int checkString(char *s) {
    int i = 0;
    for (i = 0; s[i] != 'c' && s[i] != '\0'; i++) {
        if (s[i] == 'a' || s[i] == 'b') {
            push(s[i]);
        }
        else {
            return 0;
        }
    }

    if (s[i] == '\0') {
        return 0;
    }

    i++;
    while (s[i] != '\0') {
        if (TOP >= 0 && s[i] == pop()) {
            i++;
        }
        else {
            return 0;
        }
    }

    if (TOP >= 0) {
        return 0;
    }

    return 1;
}

int main() {

    char s[100];
    printf("Enter a string: ");
    scanf("%s", s);

    if (checkString(s)) {
        printf("%s is a valid string", s);
    }
    else {
        printf("%s is an invalid string", s);
    }

    return 0;
}