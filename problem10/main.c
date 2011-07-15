#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../lib/assert.h"
#include "../lib/fmath.h"

long sum_primes_till(long n){
    long sum = 0, i;
    for (i = 2; i <= n; i++) {
        if (is_prime(i)){
            sum += i;
        }
    }
    return sum;
}

int main(int argc, void *argv) {
    assert_equals_int(sum_primes_till(10), 17);
    printf("%ld\n", sum_primes_till(2000000));
    return 0;
}
