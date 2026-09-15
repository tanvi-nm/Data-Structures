#include <stdio.h>

void removeDuplicates(int *nums, int n);

int main() {
    int n;
    printf("Enter number of elements : ");
    scanf("%d", &n);

    int nums[n];
    printf("Enter the array elements : ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    removeDuplicates(nums, n);
    printf("The array after removing duplicates is : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}

void removeDuplicates(int *nums, int n) {
    if (n == 1) {
        return;
    }

    int slow = 0;

    for (int fast = 1; fast < n; fast++) {
        if (nums[fast] != nums[slow]) {
            nums[++slow] = nums[fast];
        }
    }

    for (slow++; slow < n; slow++) {
        nums[slow] = 0;
    }
    
}