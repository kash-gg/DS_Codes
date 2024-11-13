#include<stdio.h>
void selectionsort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int min = i;
        for(int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min != i) {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

void selectionsortrecursion(int arr[],int n,int start){
     int minIndex = start;
    for (int i = start + 1; i < n; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    if (minIndex != start) {
        int temp = arr[start];
        arr[start] = arr[minIndex];
        arr[minIndex] = temp;
    }
    recursiveSelectionSort(arr, n, start + 1);
}