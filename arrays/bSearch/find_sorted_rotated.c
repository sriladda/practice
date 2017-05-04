//http://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/
#include <stdio.h>

int pivotedBinarySearch(int arr[], int low, int high, int key) {
   int mid;

   while (low <= high) {
   	   mid = low + (high - low)/2;
	   printf("low = %d, high = %d\n", low, high);
	   if (key == arr[mid]) {
		return mid;
	   }
	   if (arr[high] >= arr[mid+1])  // right side of the array is sorted
	   {
	      if ( (key >= arr[mid+1])  && (key <= arr[high]) ) { // key lies in the sorted right side
		low = mid+1;
	      } else {
		high = mid-1;
	      }
	   }
	   else { // left side is the sorted side
	      if ( (key <= arr[mid-1]) && (key >= arr[low]) ) { // key lies in the sorted left side
		high = mid - 1;
	      } else {
		low = mid+1;
	      }
	   }
   }
   return -1;
}

/* Driver program to check above functions */
int main()
{
   // Let us search 3 in below array
   int arr1[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
   int n = sizeof(arr1)/sizeof(arr1[0]);
   int key = 3;
   printf("Index: %d\n", pivotedBinarySearch(arr1, 0, n-1, key));
   return 0;
}
