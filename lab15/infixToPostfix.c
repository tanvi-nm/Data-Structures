#include <stdio.h>
#include <ctype.h>

#define MAX 100
char stack[MAX];
int TOP = -1;

void push(char ch) {
    stack[++TOP] = ch;
}

char pop() {
    return stack[TOP--];
}

char peek() {
    return stack[TOP];
}

int precedence(char ch) {
    switch (ch) {
        case '^': return 4;
        case '/': case '*':  case '%': return 3;
        case '+': case '-': return 2;
        default: return 1;
    }
}

void convertToPostfix(char * s) {
    char postfix[MAX];
    int index = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];

        if (isalnum(ch)) {
            postfix[index++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (TOP != -1 && peek() != '(') {
                postfix[index++] = pop();
            }
            if (TOP != -1) {
                pop();
            }
        }
        else {
            while (TOP != -1 && precedence(peek()) > precedence(ch)) {
                postfix[index++] = pop();
            }
            push(ch);
        }
    }

    while (TOP != -1) {
        postfix[index++] = pop();
    }

    printf("%s", postfix);
}

int main() {
    char s[] = "(a+b^c^d)*(e+f/d)";
    convertToPostfix(s);
}