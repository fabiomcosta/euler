#include <stdio.h>
#include <math.h>
#include "../assert.h"

inline long is_prime(long number){
    long sqrt_number = sqrt(number);
    long i;

    for (i = 2; i <= sqrt_number; i++){
        if (number % i == 0){
            return 0;
        }
    }

    return 1;
}

long max_prime_factor_from(long number){
    long sqrt_number = sqrt(number);
    long i;

    if (sqrt_number % 2 == 0){
        sqrt_number--;
    }

    for (i = sqrt_number; i > 0 ; i-=2){
        if (number % i == 0 && is_prime(i)){
            return i;
        }
    }

    return 1;
}

int main(int argc, void *argv) {
    assert(is_prime(1));
    assert(!is_prime(4));
    assert(is_prime(5));
    assert(!is_prime(6));
    assert(is_prime(7));
    assert_equals_int(max_prime_factor_from(13195), 29);
    printf("%li\n", max_prime_factor_from(600851475143));
    return 0;
}
