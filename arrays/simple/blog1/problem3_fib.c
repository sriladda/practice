#include <stdio.h>

int main() {
    int n = 100;
    int count;
    unsigned long long fib[100];
    for(fib[0] = 0, fib[1] = 1, count = 2; count < n; count++) {
        fib[count] = fib[count-1] + fib[count-2];
        printf("%llu " , fib[count]);
    }
    return 0;
}
