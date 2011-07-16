#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../lib/assert.h"
#include "../lib/fmath.h"

inline int number_of_numbers_generated_by_sequence_starting_at(long n) {
    int number_of_numbers = 1;
    long x = n;

    while (x > 1) {
        if (IS_EVEN(x)) {
            x /= 2;
        } else {
            x = 3 * x + 1;
        }
        number_of_numbers++;
    }

    return number_of_numbers;
}

int longgest_chain_starting_at(int n) {
    int i;
    int test;
    int biggest = 0;
    int number = 0;

    for (i = n + 1; --i;) {
        test = number_of_numbers_generated_by_sequence_starting_at(i);
        if (test > biggest){
            biggest = test;
            number = i;
        }
    }

    return number;
}

int main(int argc, void *argv) {
    assert_equals_int(number_of_numbers_generated_by_sequence_starting_at(13), 10);
    PINT(longgest_chain_starting_at(1000000))
    return 0;
}
