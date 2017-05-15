#include <stdio.h>

int main() {
    int arr[] = {1, 2,3, 4,5};
    int sum =0, i;

    i = 0;
    while (i < 5) {
        sum += arr[i];
        i++;
    }
    printf("sum = %d\n", sum);
    return 0;
}
