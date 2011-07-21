// based on http://lelanthran.com/deranged/?p=68
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "print.h"
#include "assert.h"

#ifndef __ARRAY__
#define __ARRAY__

#define ARRAY_INITIAL_LENGTH 4
#define ARRAY_GROWTH_RATE 2
#define ARRAY_DEFAULT_BLOCK_SIZE 4

#define ARRAY_GET(_array, index, _type) *((_type*)(_array.itens[index].item))
#define ARRAY_GET_PTR(_array, index, _type) (_type)(_array.itens[index].item)

#define ARRAY_PUSH(_array, val) array_push(_array, copy(&val, sizeof(val)), 1);
#define ARRAY_PUSH_PTR(_array, val) array_push(_array, val, 0);

typedef struct {
    void *item;
    char _is_copy;
} array_item;

typedef struct {
    array_item *itens;
    int length;
    int _n_allocated; //n of elements alocated in memory
} array;

void array_new(array*);
void array_push(array*, void*, char const);
int array_get(array*, char*);
void* copy(void*, int);
void array_free(array*);

#endif
