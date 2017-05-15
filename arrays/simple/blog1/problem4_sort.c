//https://ncona.com/2011/07/how-to-delete-a-commit-in-git-local-and-remote/

/*
 Eventhough this question appears tricky, it is just modified sorting question.
 In normal sorting, if 1,2,3,4,5 are given and asked to sort, you sort them 
 based on less than or greater than
 
 where as here, you need to sort all numbers based on if strcat(x,y) > strcat(y,x) 
 ie., 12 > 21 or not for integer numbers 1 and 2

 As another example if 6 and 50 are the numbers in your array,

 number 650 > 506, so the final array arrangement to get maximum number should be

 [6, 50] even though 6 < 50

 etc.,
 one number put next to another number which forms bigger number.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(int *num1, int *num2) {
    int temp;

    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void sort(int arr[], int size) {
    int i, j;
    char num[4];

    for(i = 0; i < size; i++) {
        for(j = i +1 ; j < size; j++) {
            if (arr[i]> arr[j]) {
                swap( & arr[i],  & arr[j]);
            }
        }
    }
}

void print(int arr[], int size) {
    int i;

    for(i =0;i < size; i++) {
       printf("%d   ", arr[i]);
    }
    printf("\n");
}

// driverr program to test above functions
int main()
{
    //output should be 6054854654
    int arr[] = {5, 60, 4};
    //int arr[] = {54, 546, 548, 60};

    // output should be 777776
    //int arr[] = {7, 776 , 7, 7};

    //output should be 998764543431
    //int arr[] = {1, 34, 3, 98, 9, 76, 45, 4};

    print(arr, sizeof(arr)/sizeof(arr[0]));
    sort(arr, sizeof(arr)/sizeof(arr[0]));
    print(arr, sizeof(arr)/sizeof(arr[0]));
 
   return 0;
}
