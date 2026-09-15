#include <stdio.h>

int isPrime(int n) {
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {

    int start, end;
    printf("Enter range : ");
    scanf("%d %d", start, end);

    for (int i = start; i <= end; i++) {
        if (isPrime(i)) {
            printf("%d, ", i);
        }
    }
    
    return 0;
}