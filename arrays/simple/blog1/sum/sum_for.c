#include <stdio.h>

int main() {
    int arr[] = {1, 2,3, 4,5};
    int sum =0, i;

    for (i = 0; i < 5; i++) {
        sum += arr[i];
    }
    printf("sum = %d\n", sum);
    return 0;
}
