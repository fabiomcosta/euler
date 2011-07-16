#include <assert.h>

#ifndef __assert__
#define __assert__

#define assert_equals_int(v1, v2)\
        printf("Asserting: %i %i\n", v1, v2);\
        assert(v1 == v2);

#endif
