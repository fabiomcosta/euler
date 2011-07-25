#include <math.h>

int is_prime(long number){

    long sqrt_number = sqrt(number);
    long i;

    for (i = 2; i <= sqrt_number; i++){
        if (number % i == 0){
            return 0;
        }
    }

    return 1;
}

long factorial(int number){
    if (number <= 1) {
        return 1;
    }
    return factorial(number - 1) * number;
}

