#include <stdio.h>

// Function to perform selection sort
void selection_sort(int arr[], int n) {
    int i, j, minIndex, temp;
    
    // Traverse through all elements in the array
    for (i = 0; i < n - 1; i++) {
        // Find the index of the minimum element in the unsorted part of the array
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        // Swap the found minimum element with the first element of the unsorted part
        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Call selection_sort function
    selection_sort(arr, n);
    
    // Print sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
