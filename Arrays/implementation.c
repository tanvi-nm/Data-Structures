#include <stdio.h>
#include <limits.h>
#include "array_adt_by_tnm.h"

int main() {

    Array arr = {
        {-6, 3, -8, 10, 5, -7, -9, 12, -4, 2},
        ARRAY_CAPACITY,
        10
    };

    printf("Original Array:\n");
    display(arr);

    // insert operation
    insert(&arr, 2, 99);

    printf("\nAfter inserting 99 at index 2:\n");
    display(arr);

    // get operation
    int value = getAtIndex(arr, 4);
    if(value != INT_MIN) {
        printf("\nElement at index 4 = %d\n", value);
    }

    // max operation
    int maximum = max(arr);
    if(maximum != INT_MIN) {
        printf("Maximum element = %d\n", maximum);
    }

    // rotate left by 3 elements
    rotateByK(&arr, 0, 3);     
    printf("\nAfter left rotation by 3:\n");
    display(arr);

    // arrange negatives on left
    arrangeNegativesOnLeft(&arr);
    printf("\nAfter arranging negatives on left:\n");
    display(arr);

    
    // union of two sets
    Array set1 = {
        {3, 4, 5, 6, 10},
        ARRAY_CAPACITY,
        5
    };

    Array set2 = {
        {2, 4, 5, 7, 12},
        ARRAY_CAPACITY,
        5
    };

    Array U = unionOfTwoSets(set1, set2);
    printf("\nUnion of the two sets:\n");
    display(U);

    return 0;
}