//http://www.geeksforgeeks.org/leaders-in-an-array/

#include <stdio.h>

void printLeaders(int arr[], int size) {
    int max_so_far= -1, i;

    for(i = size-1; i >=0; i--) {
        if (arr[i] > max_so_far) {
            printf("%d  ", arr[i]);
            max_so_far = arr[i];
	}
    }
}

/* Driver program to test above function */
int main()
{
    int arr[] = {16, 17, 4, 3, 5, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    printLeaders(arr, n);
    return 0;
}
