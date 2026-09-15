#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
        case '+': return (num2 + num1);
        case '-': return (num2 - num1);
        case '*': return (num2 * num1);
        case '/': 
            if (num1 == 0) {
                return -1;
            }
            else {
                return (num2 / num1);
            }
        case '^': return (int)pow(num2, num1);
        default: return -1;
    }
}

int evaluatePostfix(char *s) {
    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];
        if (isnumber(ch)) {
            push(s[i] - '0');
        }
        else {
            int num1 = pop();
            int num2 = pop();
            if (num1 >= 0 && num2 >= 0) {
                push(eval(num1, num2, ch));
            }
            else {
                printf("Invalid input!");
                return -1;
            }
        }
    }
    return pop();
}

int main() {
    char s[] = "25^";
    printf("%d", evaluatePostfix(s));
    return 0;
}