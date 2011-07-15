#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../lib/assert.h"

//a2 + b2 = c2
//a + b + c = 1000
//so a + b + sqrt(a2 + b2) = 1000
//and c = 1000 - a - b

void sum_pythagorean_equals(int* arr, int n){
    int a, b;
    for (a = 1; a < n; a++) {
        for (b = 1; b < n; b++) {
            if (a + b + sqrt(pow(a, 2) + pow(b, 2)) == n){
                arr[0] = a;
                arr[1] = b;
                return;
            }
        }
    }
}

int main(int argc, void *argv) {
    int arr[3], i, a, b, c;

    sum_pythagorean_equals(arr, 1000);

    a = arr[0];
    b = arr[1];
    c = 1000 - a - b;

    printf("%d %d %d product %d\n", a, b, c, a * b * c);

    return 0;
}
