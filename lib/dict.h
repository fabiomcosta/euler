#include "array.h"

#ifndef __DICT__
#define __DICT__

typedef struct {
    array labels;
} dict;

typedef struct {
    char *label;
    int index;
} dict_label;

dict dict_new();
dict_label dict_new_label();

void dict_set(dict*, dict_label, int);
void dict_set(dict*, char*, int);

int dict_get(dict*, dict_label);
int dict_get(dict*, char*);

#endif
