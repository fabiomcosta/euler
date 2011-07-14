#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../lib/assert.h"

#include "../lib/fmath.h"

int get_nth_prime(int n){
    int nth_prime = 1;

    while (n) {
        nth_prime++;
        if (is_prime(nth_prime)){
            n--;
        }
    } 

    return nth_prime;
}

int main(int argc, void *argv) {
    assert_equals_int(get_nth_prime(6), 13);
    printf("%d\n", get_nth_prime(10001));
    return 0;
}
