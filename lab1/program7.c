#include <stdio.h>

int main() {

    int days;
    printf("Enter days : ");
    scanf("%d", &days);

    int year = days / 365;
    days %= 365;
    int weeks = days / 7;
    days %= 7;

    printf("%d years, %d weeks, %d days", year, weeks, days);
    
    return 0;
}