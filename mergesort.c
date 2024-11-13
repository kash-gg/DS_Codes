#include<stdio.h>
void mergesort(int arr[], int beg, int end) {
    if (beg < end) {
        int mid = beg + (end - beg) / 2; // Find the middle point
        mergesort(arr, beg, mid);        // Sort first half
        mergesort(arr, mid + 1, end);    // Sort second half
        merge(arr, beg, mid, end);       // Merge the sorted halves
    }
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array: ");
    for (int i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    mergesort(arr, 0, arr_size - 1);

    printf("Sorted array: ");
    for (int i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}