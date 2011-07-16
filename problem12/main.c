#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../lib/assert.h"
#include "../lib/fmath.h"


long triangle_even_divisible_by_n(int n){
    long i = 0;
    long j;
    long triangle = 0;
    long half_triangle = 0;
    long max_test = 1;
    int n_divisors;

    while (++i) {
        triangle += i;

        n_divisors = 0;
        max_test = triangle;

        for (j = 1; j < max_test; j++) {
            if (triangle % j == 0){
                n_divisors += 2;
                max_test = triangle / j;
            }
        }

        if (n_divisors > n){
            break;
        }
    }

    return triangle;
}

int main(int argc, void *argv) {
    assert_equals_int(triangle_even_divisible_by_n(3), 6);
    assert_equals_int(triangle_even_divisible_by_n(5), 28);
    printf("%ld\n", triangle_even_divisible_by_n(500));
    return 0;
}
