#include <stdio.h>

int deleteFromSortedArray(int *nums, int n, int element);

int main() {
    int n;
    printf("Enter number of elements : ");
    scanf("%d", &n);

    int nums[n];
    printf("Enter array elements : ");
    for (int i=0; i<n; i++) {
        scanf("%d", &nums[i]);
    }

    int element;
    printf("Enter element to be deleted : ");
    scanf("%d", &element);

    int res = deleteFromSortedArray(nums, n, element);

    if (res) {
        printf("Element deleted successfully!\n");
        for (int i=0; i<n; i++) {
            printf("%d ", nums[i]);
        }
    }
    else {
        printf("Given element is not found in the array");
    }

    return 0;
}

int deleteFromSortedArray(int *nums, int n, int element) {
    if (element < nums[0] || element > nums[n-1]) {
        return 0;
    }

    int index;
    for (int i=0; i<n; i++) {
        if (element == nums[i]) {
            index = i;
            break;
        }
    }

    int i = index;
    while (i < n-1) {
        nums[i] = nums[i+1];
        i++;
    }
    nums[i] = 0;

    return 1;
}