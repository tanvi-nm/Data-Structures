#include <stdio.h>

int main() {
    
    int n;
    printf("Enter year : ");
    scanf("%d", &n);

    if ((n % 400 == 0) || (n % 4 == 0 && n % 100 != 0)) {
        printf("%d is a leap year", n);
    }
    else {
        printf("%d is not a leap year", n);
    }
    
    return 0;
}