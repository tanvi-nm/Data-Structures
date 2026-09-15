#include <stdio.h>

int main() {
    int n;
    printf("Enter number of elements : ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter array elements : ");
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("The array elements are : ");
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}