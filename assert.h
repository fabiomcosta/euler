#include <assert.h>

#define assert_equals_int(v1, v2)\
        printf("asserting: %i %i\n", v1, v2);\
        assert(v1 == v2);
