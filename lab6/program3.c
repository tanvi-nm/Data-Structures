#include <stdio.h>
#include <stdlib.h>

int main() {

    int n;
    printf("Enter the number of numbers : ");
    scanf("%d", &n);

    int sum = 0;
    int *num = (int *)malloc(sizeof(int));
    printf("Enter the numbers : ");
    while (n > 0) {
        scanf("%d", num);
        sum += *num;
        n--;
    }

    printf("The sum of entered numbers is : %d", sum);

    free(num);
    
    return 0;
}