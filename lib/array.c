#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "print.h"
#include "array.h"
#include "assert.h"


void
array_new(array* arr) {

    if (arr->itens == NULL){

        arr->itens = malloc(sizeof(*arr->itens));

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

}


void
array_push(array *arr, void *item, char const is_copy) {
    array_new(arr);
    arr->itens[arr->length].item = item;
    arr->itens[arr->length]._is_copy = is_copy;
    arr->length++;
}


void
array_free(array *arr) {
    int i;
    for (i = 0; i < arr->length; i++) {
        if (arr->itens[i]._is_copy){
            free(arr->itens[i].item);
        }
    }
    free(arr->itens);
}


void*
copy(void *value, int len) {
   void *ret = malloc(len);
   if (!ret) {
      ERROR("ERROR: value duplication failed.\n");
      exit(1);
   }
   memcpy(ret, value, len);
   return ret;
}


/*int main(){*/
    /*array a;*/
    /*a.itens = NULL;*/
    /*array_new(&a);*/

    /*assert_equals_int(a.length, 0);*/
    /*assert_equals_int(a._n_allocated, 4);*/

    /*int i = 10;*/
    /*ARRAY_PUSH(&a, i);*/

    /*assert_equals_int(a.length, 1);*/
    /*assert_equals_int(a._n_allocated, 4);*/

    /*assert_equals_int(ARRAY_GET(a, 0, int), 10);*/

    /*int j = 12, h = 13, k = 14;*/
    /*ARRAY_PUSH(&a, j);*/
    /*ARRAY_PUSH(&a, h);*/
    /*ARRAY_PUSH(&a, k);*/

    /*// iterating*/
    /*int _i;*/
    /*for (_i = 0; _i < a.length; _i++) {*/
        /*printf("a[%d]: %d\n", _i, ARRAY_GET(a, _i, int));*/
    /*}*/

    /*char b = 'c';*/
    /*char b2 = 'c';*/
    /*char b3 = 'c';*/

    /*ARRAY_PUSH(&a, b);*/
    /*ARRAY_PUSH(&a, b2);*/
    /*ARRAY_PUSH(&a, b3);*/

    /*assert(ARRAY_GET(a, 4, char) == 'c');*/
    /*assert(ARRAY_GET(a, 5, char) == 'c');*/
    /*assert(ARRAY_GET(a, 6, char) == 'c');*/

    /*char c[] = "a long phrase with some chars\n";*/

    /*ARRAY_PUSH_PTR(&a, c);*/
    /*printf("%s", ARRAY_GET_PTR(a, 7, char*));*/
    /*assert(strcmp(ARRAY_GET_PTR(a, 7, char*), "a long phrase with some chars\n") == 0);*/

    /*array_free(&a);*/

    /*return 0;*/
/*}*/

