#include <stdio.h>

// Function to left rotate an array by 'steps'
void leftRotate(int arr[], int size, int steps) {
    if (steps % 5 == 0) {
        printf("No rotation needed, as k is a multiple of 5.\n");
        return;
    }

    steps %= size; // Handle cases where steps > size

    for (int i = 0; i < steps; i++) {
        int temp = arr[0];
        for (int j = 0; j < size - 1; j++) {
            arr[j] = arr[j + 1];
        }
        arr[size - 1] = temp;
    }
}

int main() {
    int size, steps;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number of steps to rotate: ");
    scanf("%d", &steps);

    leftRotate(arr, size, steps);

    printf("Array after left rotation: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
