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

    int max = *nums;

    for (int i = 1; i < size; i++) {
        if (*(nums + i) > max) {
            max = *(nums + i);
        }
    }

    printf("The largest element of array is : %d", max);

    free(nums);
    
    return 0;
}