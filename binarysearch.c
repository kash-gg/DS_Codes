// #include<stdio.h>
// int binarysearch(int arr[],int low,int high,int key){
//     while(low<=high){
//         int mid =(low+high)/2;
//         if(arr[mid]==key){
//             return mid;
//         }
//         else if(arr[mid]<key){
//             low =mid+1;

//         }
//         else if(arr[mid]>key){
//             high = mid-1;
//         }
//         else
//         return -1;
//     }
// }

#include <stdio.h>

int binarysearch(int arr[], int low, int high, int key) {
    if (low <= high) {
        int mid = (low + high) / 2;
        
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            return binarysearch(arr, mid + 1, high, key);
        } else {
            return binarysearch(arr, low, mid - 1, key);
        }
    }
    
    return -1; // Key not found
}

int main() {
    int sze, i, key;
    
    printf("Enter the size of the array: ");
    scanf("%d", &sze);

    int arr[sze];

    printf("Enter %d elements in sorted order:\n", sze);
    for (i = 0; i < sze; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the key to search: ");
    scanf("%d", &key);

    int result = binarysearch(arr, 0, sze - 1, key);
    
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }

    return 0;
}