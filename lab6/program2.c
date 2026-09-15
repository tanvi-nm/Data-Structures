#include <stdio.h>
#include <stdlib.h>

int main() {

    int size;
    printf("Enter the number of elements : ");
    scanf("%d", &size);

    int *nums = (int *)malloc(size * sizeof(int));

    printf("Enter array elements : ");
    for (int i = 0; i < size; i++) {
        scanf("%d", (nums + i));
    }

    printf("The array elements are : ");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(nums + i));
    }

    free(nums);
    return 0;
}