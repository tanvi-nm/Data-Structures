#include <stdio.h>

#define MAX 100
int stack[MAX];
int TOP = -1;

void push(int value) {
    if (TOP >= MAX - 1) {
        printf("Stack Overflow!");
    }
    else {
        stack[++TOP] = value;
    }
}

int pop() {
    if (TOP < 0) {
        return -1;
    }
    else {
        return stack[TOP--];
    }
}

int peek() {
    if (TOP < 0) {
        return -1;
    }
    else {
        return stack[TOP];
    }
}

void stackSortable(int *a, int n) {
    int b[n];
    int expected = 1;
    int bIndex = 0;
    
    for (int i = 0; i < n; i++) {
        push(a[i]);
        while (peek() != -1 && peek() == expected) {
            b[bIndex++] = pop();
            expected++;
        }
    }

    int isSorted = 1;
    for (int i = 0; i < n-1; i++) {
        if (b[i] >= b[i+1]) {
            isSorted = 0;
            break;
        }
    }

    if (isSorted) {
        printf("YES");
    }
    else {
        printf("NO");
    }

}

int main() {

    int a[] = {1,3,4,2};
    stackSortable(a, 4);
    return 0;
}