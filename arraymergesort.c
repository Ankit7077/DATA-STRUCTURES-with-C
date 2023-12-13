#include <stdio.h>
#include <stdlib.h>


//This function takes three parameters - the array arr, and two indices l and r representing the range to be merged.
//It calculates the middle index m and the sizes of the two subarrays (n1 and n2).
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Temporary arrays L and R are created to store the elements of the two subarrays.
    int L[n1], R[n2];

   //The elements of the original array are copied into the temporary arrays.
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

  //The function then merges the two subarrays back into the original array in sorted order.(from step 27 to 51)

/*Initialization:(from step 27 to 29)

 i, j, and k are initialized to 0, representing the indices of the current elements in the arrays L, R, and the merged array arr.

k is initialized to the starting index l of the range to be merged.*/
    i = 0;
    j = 0;
    k = l;
/*Merging Loop:from (36 to 45)

The first while loop continues as long as there are elements remaining in both L and R.

If the element at L[i] is less than or equal to the element at R[j], it means the smaller element is in the left subarray. 

So, arr[k] is assigned the value of L[i], and i is incremented.
If the element at L[i] is greater than the element at R[j], 
it means the smaller element is in the right subarray. 

So, arr[k] is assigned the value of R[j], and j is incremented.
k is then incremented to move to the next position in the merged array*/
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
/*Remaining Elements in L and R: from 53 to 63

After the merging loop, there might be remaining elements in either L or R or both.

The next two while loops handle these cases:

If there are remaining elements in L, they are copied to the merged array arr.

If there are remaining elements in R, they are similarly copied to the merged array arr.

In both cases, i, j, and k are appropriately incremented.*/
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
/*After these loops,from step(43 to 74 including comments)  the merged array arr contains all the elements from the original subarrays L and R in sorted order, and the indices i, j, and k have been updated accordingly.*/

/*(From step 80 to 89) This is the recursive function for the Merge Sort algorithm.*/



void mergeSort(int arr[], int l, int r)
//It takes an array arr and two indices l and r representing the range to be sorted. 
{
    //If l is less than r, 
    if (l < r) {

    //it calculates the middle index m and recursively calls mergeSort on the two halves of the array. 

    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    // In step 91 , it calls the merge function to merge the sorted halves.
    merge(arr, l, m, r);
    }
}

void printArray(int A[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
int main() {
    int arr[] = {22 ,11 ,77,0};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    /*(In step 107  printArray(arr, arr_size); 
    calls the printArray function to print the elements of the original array.*/

    printArray(arr, arr_size);

    /* In step 111, mergeSort(arr, 0, arr_size - 1); initiates the Merge Sort algorithm on the array.
     It starts with the entire array, indicated by the range (0, arr_size - 1).*/
    
    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");

    /*In step 116 printArray(arr, arr_size); calls the printArray function again to print the elements of the array after sorting.*/
    printArray(arr, arr_size);

    return 0;
}
