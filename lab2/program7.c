#include <stdio.h>

int main() {

    int n;
    printf("Enter the number of rows : ");
    scanf("%d", &n);

    int sum = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            sum += j;
        }
    }

    printf("Sum is %d", sum);
    
    return 0;
}