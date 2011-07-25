#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../lib/print.h"
#include "../lib/assert.h"
#include "../lib/fmath.h"

/*
 * This problem shows a permutation with repetition.
 * On the given example, we always end up with a group of 4 elements, 2 vertical lines (V) and 2 horizontal lines (H).
 * For a grid of nxn, it always ends up with a group of n * 2, n V and n H.
 * A permutation for a group of n * 2, containing n V and n H equals to C(n*2,n) * C(n,n) => C(n*2,n)
 * C(n*2, n) = factorial(n*2) / (factorial(n) * factorial(n))
 *
 */

int main(int argc, void *argv) {

    assert_equals_int(factorial(3), 6);
    assert_equals_int(factorial(4), 24);

    /*
     * factorial(40) / (factorial(20) * factorial(20))
     */

    // factorial(40) is too long I had to reduce the division it by hand
    PLONG(37L * 35 * 33 * 31 * 29 * 13 * 23 * 3 * 2 * 2);
    return 0;
}
