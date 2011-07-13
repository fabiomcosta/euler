#include <stdio.h>
#include "../assert.h"

int even_sum_fibonacci_below(int number){
    int a = 1;
    int b = 2;
    int sum = 2;
    int temp;

    if (number <= 2){
        return 0;
    }

    do {
        temp = b;
        b += a;
        a = temp;
        if (b % 2 == 0){
            sum += b;
        }
    } while(b < number);

    return sum;
}

int main(int argc, void *argv) {
    assert_equals_int(even_sum_fibonacci_below(0), 0);
    assert_equals_int(even_sum_fibonacci_below(2), 0);
    assert_equals_int(even_sum_fibonacci_below(3), 2);
    printf("%d\n", even_sum_fibonacci_below(4000000));
    return 0;
}
