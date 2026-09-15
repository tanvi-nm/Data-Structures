#include <stdio.h>

int main() {
    
    int seconds;
    printf("Enter seconds : ");
    scanf("%d", &seconds);

    int hours = seconds / 3600;
    seconds %= 3600;
    int minutes = seconds / 60;
    seconds %= 60;

    printf("%d:%d:%d", hours, minutes, seconds);
    
    return 0;
}