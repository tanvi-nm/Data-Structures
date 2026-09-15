#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50
char stack[MAX];
int TOP = -1;

void push(char ch) {
    stack[++TOP] = ch;
}

char pop() {
    if (TOP < 0) return -1;
    return stack[TOP--];
}

char peek() {
    if (TOP < 0) return -1;
    return stack[TOP];
}

int g(char ch) {
    switch ( ch) {
        case '+': case '-': return 2;
        case '*': case '/': return 4;
        case '^': return 5;
        case '(': return 0;
    }
    return -1;
}

char* convertToPostfix(char *s) {
    int n = strlen(s);
    push('(');
    s[n] = ')';
    s[n+1] = '\0';
    n++;

    char * str = (char *)malloc(n);
    int index = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];

        if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (g(peek()) >= g(ch)) {
                str[index++] = pop();
            }
            push(ch);
        }

        else if (ch == '^') {
            while (g(peek()) > g(ch)) {
                str[index++] = pop();
            }
            push(ch);
        }

        else if (ch == '(') {
            push(ch);
        }

        else if (ch == ')') {
            char temp = pop();
            while (temp != '(') {
                str[index++] = temp;
                temp = pop();
            }
        }

        else {
            str[index++] = ch;
        }
    }

    return str;
}

int main() {

    char s[50] = "(a+b^c^d)*(e+f/d)";

    char *str = convertToPostfix(s);

    printf("%s", str);

    return 0;
}