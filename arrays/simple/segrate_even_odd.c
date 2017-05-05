//http://www.geeksforgeeks.org/segregate-0s-and-1s-in-an-array-by-traversing-array-once/
#include <stdio.h>

void segregateEvenOdd(int arr[], int arr_size) {
    int left = 0, right = arr_size-1, temp;

    while (left < right) {
        while (left < right && arr[left]%2 == 0) {
            left++;
        }
        while ( right > left && arr[right]%2 == 1) {
            right--;
        }
        if (arr[left]%2 == 1 && arr[right]%2 == 0) {
	    temp = arr[left];
	    arr[left] = arr[right];
	    arr[right] = temp;
            left++;
            right--;
	}
    }
}

/* driver program to test */
int main()
{
    int arr[] = {12, 34, 45, 9, 8, 90, 3};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    int i = 0;
 
    segregateEvenOdd(arr, arr_size);
 
    printf("Array after segregation ");
    for (i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
 
    printf("\n"); 
    return 0;
}
