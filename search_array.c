#include <stdio.h>

// Function to perform Linear Search (Works on unsorted arrays)
// Time Complexity: O(n)
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Target found, return index
        }
    }
    return -1; // Target not found
}

// Simple Bubble Sort function needed before executing Binary Search
void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to perform Binary Search (Requires sorted array)
// Time Complexity: O(log n)
int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // Avoids integer overflow

        if (arr[mid] == target) {
            return mid; // Target found, return index
        }
        if (arr[mid] < target) {
            low = mid + 1; // Search right half
        } else {
            high = mid - 1; // Search left half
        }
    }
    return -1; // Target not found
}

int main() {
    int arr[] = {42, 15, 8, 23, 91, 4, 16};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 23;

    // 1. Linear Search Example
    printf("--- Linear Search ---\n");
    int linearResult = linearSearch(arr, size, target);
    if (linearResult != -1) {
        printf("Element %d found at index %d\n\n", target, linearResult);
    } else {
        printf("Element %d not found\n\n", target);
    }

    // 2. Binary Search Example
    // Sorting the array first as binary search requires an ordered array
    sortArray(arr, size); 

    printf("--- Binary Search (after sorting) ---\n");
    int binaryResult = binarySearch(arr, size, target);
    if (binaryResult != -1) {
        printf("Element %d found at index %d\n", target, binaryResult);
    } else {
        printf("Element %d not found\n", target);
    }

    return 0;
}
