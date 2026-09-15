#include <stdio.h>

#define MAX 100
int Q[MAX];
int F = -1, R = -1;

void enqueue(int val) {
    if (R >= MAX - 1) {
        printf("Queue overflow!");
    }
    else {
        Q[++R] = val;
        if (F == -1) {
            F = 0;
        }
    }
}

int dequeue() {
    if (F <= -1) {
        printf("Queue underflow!");
        return -1;
    }
    int Y = Q[F];
    if (F == R) {
        F = -1;
        R = -1;
    }
    else {
        F++;
    }
    return Y;
}

void display() {
    for (int i = F; i <= R; i++) {
        printf("%d, ", Q[i]);
    }
    printf("\n");
}

int main() {

    enqueue(1);
    display();
    enqueue(2);
    display();
    enqueue(3);
    display();
    enqueue(4);
    display();

    dequeue();
    display();
    dequeue();
    display();

    enqueue(5);
    display();

    return 0;
}