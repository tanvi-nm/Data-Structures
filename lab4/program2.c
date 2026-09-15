#include <stdio.h>
#include <limits.h>

int delete(int *nums, int n, int index);

int main() {
    int n;
    printf("Enter number of elements : ");
    scanf("%d", &n);

    int nums[n];
    printf("Enter array elements : ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int index;
    printf("Enter index of element to be deleted : ");
    scanf("%d", &index);

    int res = delete(nums, n, index);
    if (res != INT_MIN) {
        printf("Deleted element : %d\n", res);
        for (int i = 0; i < n; i++) {
            printf("%d ", nums[i]);
        }
    }
    else {
        printf("Element could not be deleted!");
    }

    return 0;
}

int delete(int *nums, int n, int index) {
    if (index < 0 || index >= n) {
        return INT_MIN;
    }

    int element = nums[index];

    for (int i=index; i<n-1; i++) {
        nums[i] = nums[i+1];
    }
    nums[n-1] = 0;

    return element;
}