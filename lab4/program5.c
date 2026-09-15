#include <stdio.h>

void deleteDuplicates(int *nums, int n);

int main() {

    int n;
    printF("Enter number of elements : ");
    scanf("%d", &n);

    int nums[n];
    printf("Enter elements of array : ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    deleteDuplicates(nums, n);

    for (int i=0; i<n; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}

void deleteDuplicates(int *nums, int n) {
    int i=0, j = 1,k=1;
    for (i=0; i<n; i++) {
        while (nums[i] == nums[j]) {
            j++;
        }
        
    }
}