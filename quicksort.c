#include<stdio.h>
void quicksort(int arr[],int low,int high){
    int pivot,i,j;
    if(low<high){
        pivot=low;
        i=low;
        j=high;
        while(i<j){
            while(arr[i]<=arr[pivot]&& i<=high){
                i++;
            }
            while(arr[j]>arr[pivot]&&j>=low){
                j--;
            }
            if(i<j){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;

        quicksort(arr, low, j - 1); 
        quicksort(arr, j + 1, high); 
    }
}