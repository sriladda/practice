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

int my_atoi(char *str) {
    int num;

    if (str == NULL) return 0;

    num = 0;
    while (*str) {
       num = (num *10) + (*str - '0');
       str++;
    }
    return num;
}

void swap(int *num1, int *num2) {
    int temp;

    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int is_swap_needed(int num1, int num2) 
{
    char str1[10], str2[10];
    char * str3 = malloc(10);
    char * str4 = malloc(10);

    snprintf(str1, 4, "%d", num1);
    snprintf(str2, 4, "%d", num2);

    strcat(str3, str1);
    strcat(str3, str2);

    strcat(str4,str2);
    strcat(str4,str1);

    if ( my_atoi(str3) > my_atoi(str4) )  {
        return 0; //swap not needed
    }
    else {
        return 1; //swap needed.
    }
}

void print(int arr[], int size) {
    int i;

    for(i =0;i < size; i++) {
       printf("%d   ", arr[i]);
    }
    printf("\n");
}

void printLargest(int arr[], int size) {
    int i, j;
    char num[4];

    for(i = 0; i < size; i++) {
        for(j = i +1 ; j < size; j++) {
            if(is_swap_needed(arr[i], arr[j]) ) {
                swap( & arr[i],  & arr[j]);
            }
        }
    }
}

// driverr program to test above functions
int main()
{

    //int arr[] = {5, 60};, just example to understand the problem itself,,:-)

    // Test Case 1
    int arr1[] = {54, 546, 548, 60};
    printf("Expected output is: 60 548 546 54\n");

    printf("Given array is: ");
    print(arr1, sizeof(arr1)/sizeof(arr1[0]));
    printLargest(arr1, sizeof(arr1)/sizeof(arr1[0]));
 
    printf(" Maximum number formed arrangement is: ");
    print(arr1, sizeof(arr1)/sizeof(arr1[0]));


    // Test case 2
    int arr2[] = {7, 776 , 7, 7};
    printf("Expected output is: 7 7 7 776\n");

    printf("Given array is: ");
    print(arr2, sizeof(arr2)/sizeof(arr2[0]));
    printLargest(arr2, sizeof(arr2)/sizeof(arr2[0]));
 
    printf(" Maximum number formed arrangement is: ");
    print(arr2, sizeof(arr2)/sizeof(arr2[0]));

    // Test case 3
    int arr3[] = {1, 34, 3, 98, 9, 76, 45, 4};
    printf("Expected output is: 9 98 76 45 4 34 3 1\n");

    printf("Given array is: ");
    print(arr3, sizeof(arr3)/sizeof(arr3[0]));

    printLargest(arr3, sizeof(arr3)/sizeof(arr3[0]));
 
    printf(" Maximum number formed arrangement is: ");
    print(arr3, sizeof(arr3)/sizeof(arr3[0]));

   return 0;
}
