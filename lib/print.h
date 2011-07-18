#ifndef __PRINT__
#define __PRINT__

#define PINT(n) printf("%d\n", n);
#define PLONG(n) printf("%ld\n", n);

#define ERROR(...) fprintf(stderr, __VA_ARGS__);

#endif
