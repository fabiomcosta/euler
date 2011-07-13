#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../assert.h"

long sum_of_square_till(long n){
    long sum = 0;
    long i;

    for (i = 1; i <= n; i++) {
        sum += pow(i, 2);
    }

    return sum;
}

long square_of_sum_till(long n){
    long sum = 0;
    long i;

    for (i = 1; i <= n; i++) {
        sum += i;
    }

    return pow(sum, 2);
}

int main(int argc, void *argv) {
    assert_equals_int(sum_of_square_till(10), 385);
    assert_equals_int(square_of_sum_till(10), 3025);
    assert_equals_int(square_of_sum_till(10) - sum_of_square_till(10), 2640);

    printf("%ld\n", square_of_sum_till(100) - sum_of_square_till(100));

    return 0;
}
