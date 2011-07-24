#include "dict.h"

void
dict_new_label(dict_label *dict_label, char *name){
    dict_label->name = name;
}

void
dict_add(array *dict, dict_label *label,  void *value){
    label->index = dict->length;
    ARRAY_PUSH_PTR(dict, value);
}

void*
dict_get(array *dict, dict_label* label){
    return dict->itens[label->index].item;
}

int main() {

    DICT_NEW_LABEL(label, "nome");

    assert(strcmp(label.name, "nome") == 0);

    DICT_NEW(_dict);
    int a = 10;

    dict_add(&_dict, &label, &a);

    assert(DICT_GET(&_dict, &label, int*) == 10);

    array_free(&_dict);

    return 0;
}
