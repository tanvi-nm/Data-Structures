#include <stdio.h>

void merge(int *nums1, int m, int *nums2, int n, int *mergedArray);

int main() {

    int m, n;
    printf("Enter number of elements in array 1  : ");
    scanf("%d", &m);

    printf("Enter number of elements in array 2 : ");
    scanf("%d", &n);

    int nums1[m];
    int nums2[n];

    printf("Enter elements of array 1 : ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &nums1[i]);
    }

    printf("Enter elements of array 2 : ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums2[i]);
    }

    int mergedArray[m+n];
    merge(nums1, m, nums2, n, mergedArray);
    for (int i = 0; i < m + n; i++) {
        printf("%d ", mergedArray[i]);
    }

    return 0;
}

void merge(int *nums1, int m, int *nums2, int n, int *mergedArray) {
    int i;
    for (i=0; i<m; i++) {
        mergedArray[i] = nums1[i];
    }
    for (; i < m+n; i++) {
        mergedArray[i] = nums2[i-m];
    }
}