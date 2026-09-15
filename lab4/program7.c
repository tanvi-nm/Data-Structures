#include <stdio.h>

void toggleCase(char *str);

int main() {
    char str[100];
    printf("Enter a string : ");
    scanf("%s", str);

    toggleCase(str);
    printf("String after toggling the cases of it's characters : %s", str);

    return 0;
}

void toggleCase(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        char temp = str[i];
        if (temp >= 65 && temp <= 90) {
            str[i] += 32;
        }
        else if (temp >= 97 && temp <= 122) {
            str[i] -= 32;
        }
        i++;
    }
}