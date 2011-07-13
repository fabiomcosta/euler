#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../assert.h"


int is_divisible_by_all_less_than(int max_divisor, int number){
    int i;
    int is_divisible = 1;

    for (i = 2; i <= max_divisor; i++) {
        if (number % i != 0){
            is_divisible = 0;
            break;
        }
    }

    return is_divisible;
}


int min_divisible_by_all_less_than(int max_divisor){
    int n = 1;

    while (1) {
        if (is_divisible_by_all_less_than(max_divisor, n)){
            return n;
        }
        n++;
    }

    return 0;
}


int main(int argc, void *argv) {
    assert_equals_int(min_divisible_by_all_less_than(10), 2520);
    printf("%d\n", min_divisible_by_all_less_than(20));
    return 0;
}
