#include <stdio.h>
#include "../assert.h"

int sum_multiples_below(int number){
    int sum = 0;
    while (number-=1){
        if (number % 3 == 0 || number % 5 == 0){
            sum += number;
        }
    }
    return sum;
}

int main(int argc, void *argv) {
    assert_equals_int(sum_multiples_below(10), 23);
    printf("%d\n", sum_multiples_below(1000));
    return 0;
}
