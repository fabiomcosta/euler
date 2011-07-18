#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "print.h"
#include "array.h"
#include "assert.h"


array*
array_new(array* arr, int block_size) {

    if (!arr){
        arr = malloc(sizeof(*arr));

        if (!arr){
            ERROR("ERROR: Couldn't allocate memory.\n");
            return NULL;
        }

        arr->length = 0;
        arr->_n_allocated = 0;
        arr->_block_size = block_size;
    }

    if (arr->length == arr->_n_allocated) {
        int alloc;

        if (arr->_n_allocated == 0) {
            alloc = 4;
        } else {
            alloc = arr->_n_allocated * 2;
        }

        void *tmp_buffer = realloc(arr->itens, (alloc * arr->_block_size));

        if (!tmp_buffer) {
            free(tmp_buffer);
            ERROR("ERROR: Couldn't realloc memory.\n");
            return NULL;
        }

        arr->itens = tmp_buffer;
        arr->_n_allocated = alloc;
    }

    return arr;
}


array*
array_alloc(array* arr) {
    if (!arr) {
        return array_new(arr, 4);
    }
    return array_new(arr, arr->_block_size);
}


array*
array_push(array *arr, void *item) {
    arr = array_alloc(arr);
    arr->itens[arr->length++] = item;
    return arr;
}


void
array_free(array *arr) {
    free(arr->itens);
    free(arr);
}


void*
array_copy_value(void *value, int len) {
   void *ret = malloc(len);
   if (!ret) {
      ERROR("ERROR: value duplication failed.\n");
      return NULL;
   }
   memcpy(ret, value, len);
   return ret;
}


int main(){
    array *a = NULL;
    a = array_new(a, sizeof(int));

    assert_equals_int(a->length, 0);
    assert_equals_int(a->_block_size, 4);
    assert_equals_int(a->_n_allocated, 4);

    int b = 10;
    a = ARRAY_PUSH(a, b);

    assert_equals_int(a->length, 1);
    assert_equals_int(a->_block_size, 4);
    assert_equals_int(a->_n_allocated, 4);

    assert_equals_int(ARRAY_GET(a, 0, int), 10);

    array *aa = NULL;
    aa = array_new(aa, sizeof(char));

    char bb = 'c';

    aa = array_push(aa, &bb);

    assert(ARRAY_GET(aa, 0, char) == 'c');

    /*a = ARRAY_PUSH(a, 20);*/

    /*int n = 10;*/

    /*array_push(a, &n);*/

    /*array_push(&a, &11);*/
    /*array_push(&a, &12);*/

    /*assert_equals_int(a.length, 1);*/

    /*assert(strcmp(a.itens[0].key, "something") == 0);*/
    /*assert(strcmp(a.itens[1].key, "other") == 0);*/
    /*assert(strcmp(a.itens[2].key, "oops") == 0);*/

    /*assert(array_contains(&a, "something"));*/
    /*assert(!array_contains(&a, "err"));*/

    /*assert_equals_int(array_get(&a,"something"), 10);*/
    /*assert_equals_int(array_get(&a, "other"), 11);*/
    /*assert_equals_int(array_get(&a, "err"), -1);*/

    array_free(a);
    array_free(aa);

    /*int c = 2;*/
    /*void **d;*/
    /*PINT(sizeof d);*/

    /*typeof(d) b = 5;*/
    /*PINT(b);*/

    return 0;
}

