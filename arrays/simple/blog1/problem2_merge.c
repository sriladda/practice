#include <stdio.h>

int main() {
    int arr1[] = {'a', 'b', 'c'};
    int arr2[] = {1, 2, 3};
    int arr3[6];
    int i, k;

    for(i=0, k=0; i < 3; i++) {
        arr3[k++] = arr1[i];
        arr3[k++] = arr2[i];
    }
    k--;
    for(k = 0; k <6; k++) {
       printf("%d           ", arr3[k]);
    }
    return 0;
}
