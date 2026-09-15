#include <stdio.h>

int main() {

    int m,n;
    printf("Enter numbers m and n : ");
    scanf("%d", &n);

    int sum = 0;
    for (int i = m; i<=n; i++) {
        sum += i;
    }

    printf("Sum of elements from %d to %d is : %d", m,n,sum);

    return 0;

}