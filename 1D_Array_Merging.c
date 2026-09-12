#include <stdio.h>

int main() {
    int arr1[5] = {1, 3, 5, 7, 9};
    int arr2[5] = {2, 4, 6, 8, 10};
    int size1 = 5;
    int size2 = 5;
    
    int mergedSize = size1 + size2;
    int merged[mergedSize];

    // Copy elements from the first array
    for (int i = 0; i < size1; i++) {
        merged[i] = arr1[i];
    }

    // Copy elements from the second array
    for (int i = 0; i < size2; i++) {
        merged[size1 + i] = arr2[i];
    }

    // Print the merged array
    printf("Merged Array: ");
    for (int i = 0; i < mergedSize; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}