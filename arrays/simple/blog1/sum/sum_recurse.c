#include <stdio.h>

int sum(int arr[],int index, int size) {
    if (index == size) {
        return  0;
    }
    return arr[index++] + sum(arr, index, size);
}
    
int main() {
    int arr[] = {1, 2,3, 4,5};

    printf("sum = %d\n", sum(arr, 0, 5));
    return 0;
}
