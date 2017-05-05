//http://www.geeksforgeeks.org/search-almost-sorted-array/

#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key) {
   int mid;

    while (low <= high) {
        mid = low + (high -low)/2;
        if (arr[mid] == key) return mid;
        if (arr[mid - 1] == key) return mid - 1;
        if (arr[mid + 1] == key) return mid + 1;
        if ( key > arr[mid])  // arr[mid+2] onwards must always be > arr[mid]
        {
            low = mid + 2;
        } else {
            high = mid - 2;
        }
    }
    return -1;
}


// Driver program to test above function
int main(void)
{
   int arr[] = {3, 2, 10, 4, 40};
   int n = sizeof(arr)/ sizeof(arr[0]);
   int x = 4;
   int result = binarySearch(arr, 0, n-1, x);
   (result == -1)? printf("Element is not present in array\n")
                 : printf("Element is present at index %d\n", result);
   return 0;
}
