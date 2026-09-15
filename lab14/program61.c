#include <stdio.h>

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

int validParentheses(char *s) {
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] == '{' || s[i] == '(' || s[i] == '[') {
            if (push(s[i]) == 0) {
                return 0;
            }
        }
        else if (s[i] == '}' || s[i] == ']' || s[i] == ')') {
            char fromStack = pop();
            if (fromStack > 0) {
                if ((s[i] == '}' && fromStack != '{') || (s[i] == ']' && fromStack != '[') || (s[i] == ')' && fromStack != '(')) {
                    return 0;
                }
            }
            else {
                return 0;
            }
        }
        else {
            return 0;
        }
        i++;
    }
    return 1;
}

int main() {
    char s[100];
    printf("Enter a string : ");
    scanf("%s", s);

    if (validParentheses(s)) {
        printf("Valid string");
    }
    else {
        printf("Invalid string");
    }

    return 0;
}