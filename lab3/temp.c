#include <stdio.h>
#include <string.h>

int * returnLocalArray();
int returnLocalVariable();

int main() {
    
    returnLocalArray();

    int n = returnLocalVariable();

    return 0;
}

int * returnLocalArray() {
    int arr[5] = {1,2,3,4,5};
    return arr;
}

int returnLocalVariable() {
    int count = 5;
    return count;
}