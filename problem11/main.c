#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../lib/assert.h"
#include "../lib/fmath.h"


int main(int argc, void *argv) {
    char _char;
    int lines = 0,
        cols = 0;

    while (1) {
        _char = getchar();

        if (_char == EOF) {
            break;
        }

        if (_char == '\n') {
            lines++;
        }

        if (_char == ' ') {
            cols++;
        }
    }

    printf("lines %d\n", lines);
    printf("cols %d\n", cols);

    return 0;
}
