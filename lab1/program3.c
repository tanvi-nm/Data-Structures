#include <stdio.h>

int main() {
    
    char ch;
    printf("Enter a character : ");
    scanf("%c", &ch);

    if ((ch == 'A') || (ch == 'E') || (ch == 'I') || (ch == 'O') || (ch == 'U') || (ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u')) {
        printf("%d is a vowel", ch);
    }
    else if (ch >= 65 && ch <= 90 || ch >= 97 && ch <= 122) {
        printf("%d is a consonant", ch);
    }

    return 0;
}