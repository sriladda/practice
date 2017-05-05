//http://www.geeksforgeeks.org/maximum-difference-between-two-elements/
#include <stdio.h>

int maxDiff(int arr[], int size) {
  int max_diff_so_far = 0, i, small;

  for(i = 1, small = arr[0]; i < size; i++) {
    if ( (arr[i] - small) > max_diff_so_far ) {
      max_diff_so_far = arr[i] - small;
    }
    if (arr[i] < small) {
      small = arr[i];
    }
  }
  return max_diff_so_far;
}

/* Driver program to test above function */
int main()
{
  int arr[] = {7, 9, 5, 6, 3, 2};
  //int arr[] = {2, 3, 10, 6, 4, 8, 1};
  //int arr[] = {1, 2, 90, 10, 110};
  printf("Maximum difference is %d",  maxDiff(arr, 5));
  getchar();
  return 0;
}
