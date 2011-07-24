#include <stdio.h>
#include <string.h>
#include "array.h"

#ifndef __DICT__
#define __DICT__

#define DICT_NEW(_dict)\
    array _dict;\
    array_new(&_dict);

#define DICT_NEW_LABEL(_dict_label, _label_str)\
    dict_label _dict_label;\
    dict_new_label(&_dict_label, _label_str);

#define DICT_GET(_dict, _label, _type)\
    *(_type) dict_get(_dict, _label)

typedef struct {
    char *name;
    int index;
} dict_label;

void  dict_new_label(dict_label*, char*);
void  dict_add(array*, dict_label*, void*);
void* dict_get(array*, dict_label*);

//void dict_set(dict*, char*, int);


#endif
