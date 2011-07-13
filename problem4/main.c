#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../assert.h"

int len(int n){
    int length = 0;
    while (n){
        n /= 10;
        length++;
    }
    return length;
}

void int_to_array(int n, int* arr){
    int i = 0;
    while (n){
        arr[i] = n % 10;
        n /= 10;
        i++;
    }
}

void int_to_char(int number, char* string){
    sprintf(string, "%d", number);
}

int is_palindrome(int number){
    int number_length = len(number);
    int number_arr[number_length];

    int_to_array(number, number_arr);
    
    int i;
    int half_length = number_length / 2;

    for (i = 0; i < number_length; i++){
        if (number_arr[i] != number_arr[number_length - i - 1]){
            return 0;
        }
    }

    return 1;
}

int largest_number_from_digits(int digits){
    int n = 0, i;
    for (i = 1; i <= digits; i++) {
        n += pow(10, i - 1) * 9;
    }
    return n;
}

int largest_palindrome_from_multiply_digits(int digits){
    int largest_number = largest_number_from_digits(digits);
    int largest_number_less1_digit = largest_number_from_digits(digits - 1);

    int i;
    int j;
    int palindrome_candidate;
    int biggest_palindrome = 0;

    for (i = largest_number; i > largest_number_less1_digit; i--){
        for (j = largest_number; j > largest_number_less1_digit; j--){
            palindrome_candidate = i * j;
            if (is_palindrome(palindrome_candidate) && palindrome_candidate > biggest_palindrome){
                biggest_palindrome = palindrome_candidate;
            }
        }
    }

    return biggest_palindrome;
}

int main(int argc, void *argv) {
    assert_equals_int(len(1), 1);
    assert_equals_int(len(10), 2);
    assert_equals_int(len(256), 3);

    assert(is_palindrome(9009));
    assert(is_palindrome(32123));

    assert_equals_int(largest_number_from_digits(1), 9);
    assert_equals_int(largest_number_from_digits(2), 99);

    assert_equals_int(largest_palindrome_from_multiply_digits(2), 9009);

    printf("%d\n", largest_palindrome_from_multiply_digits(3));

    return 0;
}
