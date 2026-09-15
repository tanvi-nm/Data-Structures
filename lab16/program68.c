#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
int stack[MAX];
int TOP = -1;

void push(char ch) {
    stack[++TOP] = ch;
}

int pop() {
    return stack[TOP--];
}

int peek() {
    return stack[TOP];
}

int eval(int num1, int num2, char op) {
    switch (op) {
        case '+': return (num1 + num2);
        case '-': return (num1 - num2);
        case '*': return (num1 * num2);
        case '/': 
            if (num2 == 0) {
                return -1;
            }
            else {
                return (num1 / num2);
            }
        case '^': return (int)pow(num1, num2);
        default: return -1;
    }
}

int evaluatePrefix(char *s) {
    int n = strlen(s);

    for (int i = n - 1; i >= 0; i--) {
        char ch = s[i];
        if (isdigit(ch)) {
            push(s[i] - '0');
        }
        else {
            int num1 = pop();
            int num2 = pop();
            if (num1 >= 0 && num2 >= 0) {
                int ans = eval(num1, num2, ch);
                if (ans == -1) {
                    printf("Invalid operation!\n");
                    return -1;
                }
                else {
                    push(ans);
                }
            }
            else {
                printf("Invalid input!\n");
                return -1;
            }
        }
    }

    return pop();
}

int main() {
    char s[] = "*+35/93";
    printf("%d", evaluatePrefix(s));
    return 0;
}