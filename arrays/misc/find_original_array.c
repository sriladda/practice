//http://www.geeksforgeeks.org/find-original-array-encrypted-array-array-sums-elements/

#include <stdio.h>

void findAndPrintOriginalArray(int arr[], int n) {
    int i, total, original_ele_sum;

    for(i = 0, total = 0; i < n; i++) {
        total += arr[i]; //24 + 25+11 = 49 + 11 = 60 = (n-1) * (sum_of_unencrypted)
    }
    original_ele_sum = total/(n-1); // 60/4 = 15, because one set of elements are missing in the sum in total
    for(i = 0; i < n; i++) {
        printf(" %d   " , original_ele_sum - arr[i]);
    }
}

// Driver program to test above
int main()
{
    int arr[] = {10, 14, 12, 13, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    findAndPrintOriginalArray(arr, n);
    return 0;
}
