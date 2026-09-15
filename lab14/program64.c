#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *s, int end) {
    int i = 0;
    while (i < end) {
        char temp = s[i];
        s[i] = s[end];
        s[end] = temp;
        i++;
        end--;
    }
}

void vowelAnxiety(char *s) {
    int n = strlen(s);

    for (int i = 1; i < n; i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            reverse(s, i-1);
        }
    }
}

int main() {
    char s[] = "abcdefghij";
    vowelAnxiety(s);

    printf("%s", s);

    return 0;
}