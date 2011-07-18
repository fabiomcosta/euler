// based on http://lelanthran.com/deranged/?p=68

#ifndef __ARRAY__
#define __ARRAY__

#define ARRAY_GET(_array, index, _type) *(_type *)_array->itens[index]
#define ARRAY_PUSH(_array, val) array_push(_array, array_copy_value(&val, sizeof(val)));


typedef struct {
    void **itens;
    int length;
    int _block_size;
    int _n_allocated; //n of elements alocated in memory
} array;

array* array_new(array*, int);
array* array_alloc(array*);
//array_item array_new_item(char*, int);
array* array_push(array*, void*);
//int array_contains(array*, char*);
int array_get(array*, char*);
void* array_copy_value(void*, int);
void array_free(array*);

#endif
