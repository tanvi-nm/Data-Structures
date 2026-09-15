#include <stdio.h>

int insert(int *nums, int n, int index, int element);

int main() {

    int n;
    printf("Enter number of elements : ");
    scanf("%d", &n);

    int nums[n+1];
    printf("Enter array elements : ");
    for (int i=0; i<n; i++) {
        scanf("%d", &nums[i]);
    }

    int index, element;
    printf("Enter index to insert element at : ");
    scanf("%d", &index);

    printf("Enter element to be inserted : ");
    scanf("%d", &element);

    int res = insert(nums, n, index, element);

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

int insert(int *nums, int n, int index, int element) {
    if (index < 0 || index > (n+1)) {
        return 0;
    }

    for (int i = n; i > index; i--) {
        nums[i] = nums[i-1];
    }
    nums[index] = element;

    return 1;
}