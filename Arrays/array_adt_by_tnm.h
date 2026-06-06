#ifndef ARRAY_ADT_BY_TNM_H
#define ARRAY_ADT_BY_TNM_H

#include <stdio.h>
#include <limits.h>

#define ARRAY_CAPACITY 100

// main "data-structure" which is handling the functions
typedef struct Array {
    int A[ARRAY_CAPACITY];
    int size;
    int length;
} Array;




// helper functions

static void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

static void create(Array *arr) {
    int size, length;

    printf("Enter size (max %d) : ", ARRAY_CAPACITY);
    scanf("%d", &size);

    if (size > ARRAY_CAPACITY) {
        size = ARRAY_CAPACITY;
    }

    if (size < 0) {
        size = 0;
    }

    printf("Enter length : ");
    scanf("%d", &length);

    if (length > size) {
        length = size;
    }

    if (length < 0) {
        length = 0;
    }

    arr->size = size;
    arr->length = length;

    printf("Enter elements : ");

    for (int i = 0; i < length; i++) {
        scanf("%d", &arr->A[i]);
    }
}




// basic oprations

static void display(Array arr) {
    printf("Elements of array are : ");

    for (int i = 0; i < arr.length; i++) {
        printf("%d ", arr.A[i]);
    }

    printf("\n");
}

static int append(Array *arr, int x) {
    if (arr->length >= arr->size) {
        return 0;
    }

    arr->A[arr->length++] = x;

    return 1;
}

static int insert(Array *arr, int index, int x) {
    if (index < 0 || index > arr->length) {
        return 0;
    }

    if (arr->length >= arr->size) {
        return 0;
    }

    for (int i = arr->length - 1; i >= index; i--) {
        arr->A[i + 1] = arr->A[i];
    }

    arr->A[index] = x;
    arr->length++;

    return 1;
}

static int deleteAtIndex(Array *arr, int index) {
    if (index < 0 || index >= arr->length) {
        return INT_MIN;
    }

    int deletedElement = arr->A[index];

    for (int i = index; i < arr->length - 1; i++) {
        arr->A[i] = arr->A[i + 1];
    }

    arr->length--;

    return deletedElement;
}

static int search(Array arr, int element) {
    for (int i = 0; i < arr.length; i++) {
        if (arr.A[i] == element) {
            return i;
        }
    }

    return -1;
}

static int getAtIndex(Array arr, int index) {
    if (index < 0 || index >= arr.length) {
        return INT_MIN;
    }

    return arr.A[index];
}

static int set(Array *arr, int index, int x) {
    if (index < 0 || index >= arr->length) {
        return 0;
    }

    arr->A[index] = x;
    return 1;
}

static int min(Array arr) {
    if (arr.length == 0) {
        return INT_MIN;
    }

    int minimum = arr.A[0];

    for (int i = 1; i < arr.length; i++) {
        if (arr.A[i] < minimum) {
            minimum = arr.A[i];
        }
    }

    return minimum;
}

static int max(Array arr) {
    if (arr.length == 0) {
        return INT_MIN;
    }

    int maximum = arr.A[0];

    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > maximum) {
            maximum = arr.A[i];
        }
    }

    return maximum;
}





// array re-arrangement operations

static void reverse(Array *arr, int start, int end) {
    if (arr->length == 0) {
        return;
    }

    if (start < 0) {
        start = 0;
    }

    if (end >= arr->length) {
        end = arr->length - 1;
    }

    while (start < end) {
        swap(&arr->A[start], &arr->A[end]);
        start++;
        end--;
    }
}

static int shiftByK(Array *arr, int direction, int k) {
    if (arr->length == 0) {
        return 0;
    }

    if (k < 0) {
        return 0;
    }

    if (k >= arr->length) {
        for (int i = 0; i < arr->length; i++) {
            arr->A[i] = 0;
        }
        return 1;
    }

    if (direction == 0) {                                // left shift
        int i;
        for (i = 0; i + k < arr->length; i++) {
            arr->A[i] = arr->A[i + k];
        }
        while (i < arr->length) {
            arr->A[i++] = 0;
        }
        return 1;
    }

    if (direction == 1) {                                // right shift
        int i;
        for (i = arr->length - 1; i >= k; i--) {
            arr->A[i] = arr->A[i - k];
        }
        while (i >= 0) {
            arr->A[i--] = 0;
        }
        return 1;
    }

    return 0;
}

static int rotateByK(Array *arr, int direction, int k) {
    if (arr->length == 0) {
        return 0;
    }

    if (k < 0) {
        return 0;
    }

    k %= arr->length;

    if (k == 0) {
        return 1;
    }

    if (direction == 0) {                                // left rotate
        reverse(arr, 0, k - 1);
        reverse(arr, k, arr->length - 1);
        reverse(arr, 0, arr->length - 1);

        return 1;
    }

    if (direction == 1) {                                // right shift
        reverse(arr, 0, arr->length - k - 1);
        reverse(arr, arr->length - k, arr->length - 1);
        reverse(arr, 0, arr->length - 1);

        return 1;
    }

    return 0;
}

static int insertInSortedArray(Array *arr, int element) {
    if (arr->length >= arr->size) {
        return 0;
    }

    int i = arr->length - 1;

    while (i >= 0 && arr->A[i] > element) {
        arr->A[i + 1] = arr->A[i];
        i--;
    }

    arr->A[i + 1] = element;
    arr->length++;

    return 1;
}

static int checkIfArrayIsSorted(Array arr) {
    for (int i = 0; i < arr.length - 1; i++) {
        if (arr.A[i] > arr.A[i + 1]) {
            return 0;
        }
    }

    return 1;
}

static void arrangeNegativesOnLeft(Array *arr) {
    int i = 0;
    int j = arr->length - 1;

    while (i < j) {
        while (i < j && arr->A[i] < 0) {
            i++;
        }

        while (i < j && arr->A[j] >= 0) {
            j--;
        }

        if(i < j) {
            swap(&arr->A[i], &arr->A[j]);
            i++;
            j--;
        }
    }
}

static void selectionSort(Array *arr) {
    for (int i = 0; i < arr->length - 1; i++) {

        for (int j = i + 1; j < arr->length; j++) {

            if (arr->A[j] < arr->A[i]) {
               swap(&arr->A[i], &arr->A[j]);
            }
        }
    }
}






// set operations

static Array mergeTwoArrays(Array arr1, Array arr2) {
    selectionSort(&arr1);
    selectionSort(&arr2);

    Array arr3;

    arr3.size = ARRAY_CAPACITY;
    arr3.length = 0;

    int i = 0, j = 0;

    while (i < arr1.length && j < arr2.length) {

        if (arr1.A[i] < arr2.A[j]) {
            arr3.A[arr3.length++] = arr1.A[i++];
        }
        else {
            arr3.A[arr3.length++] = arr2.A[j++];
        }
    }

    while (i < arr1.length) {
        arr3.A[arr3.length++] = arr1.A[i++];
    }

    while (j < arr2.length) {
        arr3.A[arr3.length++] = arr2.A[j++];;
    }

    return arr3;
}

static Array unionOfTwoSets(Array set1, Array set2) {
    selectionSort(&set1);
    selectionSort(&set2);

    Array U;

    U.size = ARRAY_CAPACITY;
    U.length = 0;

    int i = 0, j = 0;

    while (i < set1.length && j < set2.length) {

        if (set1.A[i] < set2.A[j]) {
            U.A[U.length++] = set1.A[i++];
        }
        else if (set1.A[i] > set2.A[j]) {
            U.A[U.length++] = set2.A[j++];
        }
        else {
            U.A[U.length++] = set1.A[i];
            i++;
            j++;
        }
    }

    while (i < set1.length) {
        U.A[U.length++] = set1.A[i++];
    }

    while (j < set2.length) {
        U.A[U.length++] = set2.A[j++];
    }

    return U;
}

static Array intersectionOfTwoSets(Array set1, Array set2) {
    selectionSort(&set1);
    selectionSort(&set2);

    Array I;

    I.size = ARRAY_CAPACITY;
    I.length = 0;

    int i = 0, j = 0;

    while (i < set1.length && j < set2.length) {
        if (set1.A[i] < set2.A[j]) {
            i++;
        }
        else if (set1.A[i] > set2.A[j]) {
            j++;
        }
        else {
            I.A[I.length++] = set1.A[i];
            i++;
            j++;
        }
    }

    return I;
}

static Array differenceOfTwoSets(Array set1, Array set2) {
    selectionSort(&set1);
    selectionSort(&set2);

    Array D;

    D.size = ARRAY_CAPACITY;
    D.length = 0;

    int i = 0, j = 0;

    while (i < set1.length && j < set2.length) {

        if (set1.A[i] < set2.A[j]) {
            D.A[D.length++] = set1.A[i++];
        }
        else if (set1.A[i] > set2.A[j]) {
            j++;
        }
        else {
            i++;
            j++;
        }
    }

    while (i < set1.length) {
        D.A[D.length++] = set1.A[i++];
    }

    return D;
}

#endif