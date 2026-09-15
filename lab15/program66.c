#include <stdio.h>
#include <ctype.h>
#include <string.h>

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

void reverse(char * s) {
    int n = strlen(s);
    for (int i = 0; i <n/2; i++) {
        char temp = s[i];
        s[i] = s[n-i-1];
        s[n-i-1] = temp;
    }
}

void convertToPrefix(char *s) {
    char *prefix;
    int index = 0;

    reverse(s);

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            s[i] = ')';
        }
        else if (s[i] == ')') {
            s[i] = '(';
        }
    }

    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];

        if (isalnum(ch)) {
            prefix[index++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (TOP != -1 && peek() != '(') {
                prefix[index++] = pop();
            }
            if (TOP != -1){
                pop();
            }
        }
        else {
            while (TOP != -1 && precedence(peek()) >= precedence(ch)) {
                prefix[index++] = ch;
            }
            push(ch);
        }
    }

    while (TOP != -1) {
        prefix[index++] = pop();
    }
    prefix[index] = '\0';

    reverse(prefix);

    printf("%s", prefix);
}

int main() {

    char s[] = "(7+9)/(2^3)";    
    convertToPrefix(s);

    return 0;
}