#include <stdio.h>
#include <stdlib.h>

int main() {

    int *intVariable = (int *)malloc(sizeof(int));
    char *charVariable = (char *)malloc(sizeof(char));
    float *floatVariable = (float *)malloc(sizeof(float));

    printf("Enter an integer : ");
    scanf("%d", intVariable);

    scanf("%c");
    printf("Enter a character : ");
    scanf("%c", charVariable);

    printf("Enter a floating - point number : ");
    scanf("%f", floatVariable);

    printf("Integer : %d\n", *intVariable);
    printf("Character : %c\n", *charVariable);
    printf("Float : %f\n", *floatVariable);

    free(floatVariable);
    free(charVariable);
    free(intVariable);

    return 0;
}