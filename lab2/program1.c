#include <stdio.h>

int factorialLoop(int n) {
    int fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int factorial(int n) {
    if (n == 1 || n == 0) {
        return 1;
    }
    else {
        return n * factorial(n-1);
    }
}

int main() {

    int n;
    printf("Enter a number : ");
    scanf("%d", &n);

    printf("Factorial using loop : %d\n", factorialLoop(n));
    printf("Factorial using recursion : %d", factorial(n));

    return 0;
}