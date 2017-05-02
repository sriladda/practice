//http://www.geeksforgeeks.org/segregate-0s-and-1s-in-an-array-by-traversing-array-once/
#include <stdio.h>

void segregate0and1(int arr[], int arr_size) {
    int left = 0, right = arr_size-1;

    while (left < right) {
        printf("In outside while loop: left = %d right = %d\n", left, right);
        while (left < right && arr[left] == 0) {
            printf("In first inside while loop: left = %d right = %d\n", left, right);
            left++;
        }
        while ( right > left && arr[right] == 1) {
            printf("In second inside while loop: left = %d right = %d\n", left, right);
            right--;
        }
        if (arr[left] == 1 && arr[right] == 0) {
	    arr[left] = 0;
	    arr[right] = 1;
            left++;
            right--;
	}
    }
}

/* driver program to test */
int main()
{
    int arr[] = {0, 1, 0, 1, 1, 1};
    int i, arr_size = sizeof(arr)/sizeof(arr[0]);
 
    segregate0and1(arr, arr_size);
 
    printf("Array after segregation ");
    for (i = 0; i < 6; i++)
        printf("%d ", arr[i]);
 
    getchar();
    return 0;
}
