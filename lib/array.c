#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "print.h"
#include "array.h"
#include "assert.h"


array*
array_new(array* arr) {

    if (!arr){
        arr = malloc(sizeof(*arr));

        if (!arr){
            ERROR("ERROR: Couldn't allocate memory.\n");
            exit(1);
        }

        arr->length = 0;
        arr->_n_allocated = 0;
    }

    if (arr->length == arr->_n_allocated) {
        int alloc;

        if (arr->_n_allocated == 0) {
            alloc = ARRAY_INITIAL_LENGTH;
        } else {
            alloc = arr->_n_allocated * ARRAY_GROWTH_RATE;
        }

        void *tmp_buffer = realloc(arr->itens, (alloc * sizeof(*arr->itens)));

        if (!tmp_buffer) {
            free(tmp_buffer);
            ERROR("ERROR: Couldn't realloc memory.\n");
            exit(1);
        }

        arr->itens = (array_item *)tmp_buffer;
        arr->_n_allocated = alloc;
    }

    return arr;
}


array*
array_push(array *arr, void *item, char const should_free) {
    arr = array_new(arr);
    arr->itens[arr->length].item = item;
    arr->itens[arr->length].should_free = should_free;
    arr->length++;
    return arr;
}


void
array_free(array *arr) {
    int i;
    for (i = 0; i < arr->length; i++) {
        if (arr->itens[i].should_free){
            free(arr->itens[i].item);
        }
    }
    free(arr->itens);
    free(arr);
}


void*
array_copy_value(void *value, int len) {
   void *ret = malloc(len);
   if (!ret) {
      ERROR("ERROR: value duplication failed.\n");
      exit(1);
   }
   memcpy(ret, value, len);
   return ret;
}


int main(){
    ARRAY_NEW(a);

    assert_equals_int(a->length, 0);
    assert_equals_int(a->_n_allocated, 4);

    int i = 10;
    ARRAY_PUSH(a, i);

    assert_equals_int(a->length, 1);
    assert_equals_int(a->_n_allocated, 4);

    assert_equals_int(ARRAY_GET(a, 0, int), 10);

    char b = 'c';
    char b2 = 'c';
    char b3 = 'c';

    ARRAY_PUSH(a, b);
    ARRAY_PUSH(a, b2);
    ARRAY_PUSH(a, b3);

    assert(ARRAY_GET(a, 1, char) == 'c');
    assert(ARRAY_GET(a, 2, char) == 'c');
    assert(ARRAY_GET(a, 3, char) == 'c');

    char c[] = "a long phrase with some chars\n";

    ARRAY_PUSH_PTR(a, c);
    printf(ARRAY_GET_PTR(a, 4, char*));
    assert(strcmp(ARRAY_GET_PTR(a, 4, char*), "a long phrase with some chars\n") == 0);

    array_free(a);

    return 0;
}

