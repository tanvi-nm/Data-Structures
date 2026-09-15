#include <stdio.h>

#define N 100
int Q[N];
int F = -1, R = -1;

void enqueue(int val) {
    if ((R+1) % N == F) {
        printf("Queue overflow!");
    }
    else {
        R = (R+1) % N;
        Q[R] = val;
        if (F == -1) {
            F = 0;
        }
    }
}

int dequeue() {
    if (F == -1) {
        printf("Queue underflow!");
        return -1;
    }
    int deletedValue = Q[F];
    if (F == R) {
        F = -1;
        R = -1;
    }
    else {
        F = (F + 1) % N;
    }
    return deletedValue;
}

void display() {
    if (F == -1) {
        return;
    }
    else {
        int T = F;
        while (T != R) {
            printf("%d ", Q[T]);
            T = (T + 1) % N;
        }
        printf("%d\n", Q[T]);
    }
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