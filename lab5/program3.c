#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int isAnagram(char *str1, char *str2);

int main() {

    srand(time(NULL));

    int n;
    printf("Enter number of words : ");
    scanf("%d", &n);
    
    char words[n][100];

    printf("Enter words : ");
    for (int i=0; i<n; i++) {
        scanf("%s", words[i]);
    }

    int randomIndex = rand() % n;

    // printf("Word : %s\n", words[randomIndex]);

    printf("Enter another word : ");
    char str[100];
    scanf("%s", str);

    int res = isAnagram(words[randomIndex], str);
    if (res) {
        printf("%s is an anagram of %s", str, words[randomIndex]);
    }
    else {
        printf("%s is not an anagram of %s", str, words[randomIndex]);
    }

    return 0;
}

int isAnagram(char *str1, char *str2) {

    int freq[26] = {0};

    int i = 0;
    while (str1[i] != '\0') {
        char temp = str1[i];
        if (temp >= 65 && temp <= 90) {
            freq[temp-65]++;
        }
        else if (temp >= 97 && temp <= 122) {
            freq[temp-97]++;
        }
        i++;
    }


    i = 0;
    while (str2[i] != '\0') {
        char temp = str2[i];
        if (temp >= 65 && temp <= 90) {
            freq[temp-65]--;
        }
        else if (temp >= 97 && temp <= 122) {
            freq[temp-97]--;
        }
        i++;
    }

    for (int i=0; i<26; i++) {
        if (freq[i] != 0) {
            return 0;
        }
    }
    
    return 1;
}