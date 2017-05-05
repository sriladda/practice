//http://www.geeksforgeeks.org/to-find-smallest-and-second-smallest-element-in-an-array/

#include <stdio.h>

void print2Smallest(int arr[], int n) {
    int smallest=arr[0], second_smallest=arr[0], i;

    for(i = 0; i <n; i++) {
        if (arr[i] < smallest) {
		second_smallest = smallest;
		smallest = arr[i];
	}
        else if ( arr[i] > smallest && arr[i] < second_smallest) {//ie.,arr[i] is > smallest but < second_smallest
		second_smallest = arr[i];
	}
    }
    printf("smallest = %d second_smallest = %d\n", smallest, second_smallest);
}

/* Driver program to test above function */
int main()
{
    int arr[] = {12, 13, 1, 10, 34, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    print2Smallest(arr, n);
    return 0;
}
