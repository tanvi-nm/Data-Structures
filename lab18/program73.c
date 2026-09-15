#include <stdlib.h>

#define N 100
int Q[N];
int F = -1, R = -1;

void insertAtFront(int val) {
    if (F == 0) {
        printf("Queue overflow!");
        return;
    }
    else if (F == -1) {
        F = 0;
        R = 0;
    }
    else {
        F--;
    }
    Q[F] = val;
}

void insertAtEnd(int val) {
    if (R >= N - 1) {
        printf("Queue overflow!");
    }
    else {
        Q[++R] = val;
        if (F == -1) {
            F = 0;
        }
    }
}

int deleteFromFront() {
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

int deleteFromRear() {
    if (R == -1) {
        printf("Queue underflow!");
        return -1;
    }
    int Y = Q[R];
    if (R == F) {
        R = 0;
        F = 0;
    }
    else {
        R--;
    }
    return Y;
}