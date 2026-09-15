#include <stdio.h>
#include <stdlib.h>

int main() {

    int size;
    printf("Enter the number of elements : ");
    scanf("%d", &size);

    int *nums = (int *)malloc(size * sizeof(int));

    int i, j;

    printf("Enter array elements : ");
    for (i = 0; i < size; i++) {
        scanf("%d", (nums + i));
    }

    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            if (*(nums + j) < *(nums + i)) {
                int temp = *(nums + i);
                *(nums + i) = *(nums + j);
                *(nums + j) = temp;
            }
        }
    }


    printf("The sorted array is : ");
    for (i = 0; i < size; i++) {
        printf("%d ", *(nums + i));
    }

    free(nums);

    return 0;
}