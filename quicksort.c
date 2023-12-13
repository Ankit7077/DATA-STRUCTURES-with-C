#include <stdio.h>

// Function to swap two elements in an array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
//partition function:

int partition(int arr[], int left, int right) {
 /*It chooses the rightmost element as the pivot.
It initializes an index i to keep track of the smaller element.*/

    int pivot = arr[right];
    int i = left - 1;
//It traverses through the array
    for (int j = left; j <= right - 1; j++) {
        // if an element is smaller than or equal to the pivot, it swaps the element with the element at index i.
        if(arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    // Swap arr[i + 1] and arr[right] (put the pivot in the correct position)
    swap(&arr[i + 1], &arr[right]);
    
    // Return the pivot index
    return i + 1;
}

//quickSort function:

// Function to perform Quick Sort
void quickSort(int arr[], int left, int right) {
   // If the left index is less than the right index, it means there is more than one element in the array.
    if (left < right) {
        // Find the pivot element such that
        // elements smaller than the pivot are on the left
        // elements greater than the pivot are on the right
        //It calls the partition function to find the partitioning index (pi).
        int pivotIndex = partition(arr, left, right);
        //It recursively applies the quickSort function to the sub-arrays before and after the partition.
        quickSort(arr, left, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, right);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    printArray(arr, size);

    // Perform Quick Sort
    quickSort(arr, 0, size - 1);

    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}
