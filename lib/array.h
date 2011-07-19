// based on http://lelanthran.com/deranged/?p=68

#ifndef __ARRAY__
#define __ARRAY__

#define ARRAY_INITIAL_LENGTH 4
#define ARRAY_GROWTH_RATE 2
#define ARRAY_DEFAULT_BLOCK_SIZE 4

#define ARRAY_NEW(_array)\
    array *_array = NULL;\
    _array = array_new(_array);

#define ARRAY_GET(_array, index, _type) *((_type *)(_array->itens[index].item))
#define ARRAY_GET_PTR(_array, index, _type) (_type)(_array->itens[index].item)

#define ARRAY_PUSH(_array, val) _array = array_push(_array, array_copy_value(&val, sizeof(val)), 1);
#define ARRAY_PUSH_PTR(_array, val) _array = array_push(_array, val, 0);

typedef struct {
    void *item;
    char should_free;
} array_item;

typedef struct {
    array_item *itens;
    int length;
    int _n_allocated; //n of elements alocated in memory
} array;

array* array_new(array*);
//array_item array_new_item(char*, int);
array* array_push(array*, void*, char const);
//int array_contains(array*, char*);
int array_get(array*, char*);
void* array_copy_value(void*, int);
void array_free(array*);

#endif
