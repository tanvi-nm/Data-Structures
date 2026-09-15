#include <stdio.h>

int insertInSortedArray(int *nums, int n, int element);

int main() {

    int n;
    printf("Enter number of elements : ");
    scanf("%d", &n);

    int nums[n+1];
    printf("Enter array elements : ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int element;
    printf("Enter element to be insered : ");
    scanf("%d", &element);

    int res = insertInSortedArray(nums, n, element);

    if (res) {
        printf("Element inserted successfully!\n");
        for (int i=0; i<=n; i++) {
            printf("%d ", nums[i]);
        }
    }
    else {
        printf("Element could not be inserted!");
    }

    return 0;
}

int insertInSortedArray(int *nums, int n, int element) {
    if (element >= nums[n-1]) {
        nums[n] = element;
        return 1;
    }

    int i = n-1;
    while (nums[i] > element && i >= 0) {
        nums[i+1] = nums[i];
        i--;
    }
    nums[i+1] = element;

    return 1;
}