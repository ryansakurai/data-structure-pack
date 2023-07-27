/**
 *  Array implementation of a list
 * 
 *  Author: Ryan Sakurai
 */

#include "array_list.h"

#define MIN_ALLOC 1

void __set_size(ArrayList *list, unsigned size) {
    list->size = size;

    while(size > list->allocation)
        list->allocation *= 2;
    while(size <= list->allocation/4 && list->allocation/2 >= MIN_ALLOC)
        list->allocation /= 2;

    list->array = realloc(list->array, list->allocation * sizeof(T));
}

void __swap(ArrayList *list, unsigned index_a, unsigned index_b) {
    T temp = list->array[index_a];
    list->array[index_a] = list->array[index_b];
    list->array[index_b] = temp;
}

void al_init(ArrayList *list) {
    list->array = malloc(MIN_ALLOC * sizeof(T));
    list->allocation = MIN_ALLOC;
    list->size = 0;
}

void al_destroy(ArrayList *list) {
    free(list->array);
    list->array = NULL;
    list->size = 0;
    list->allocation = 0;
}

void al_push(ArrayList *list, T data) {
    __set_size(list, list->size + 1);
    list->array[list->size - 1] = data;
}

bool al_insert(ArrayList *list, unsigned index, T data) {
    if(index >= list->size)
        return false;

    __set_size(list, list->size+1);
    for(int i = list->size-1; i > index; i--)
        list->array[i] = list->array[i-1];
    list->array[index] = data;
    return true;
}

bool al_remove(ArrayList *list, unsigned index) {
    if(index >= list->size)
        return false;

    for(int i=index; i+1 < list->size; i++)
        list->array[i] = list->array[i+1];
    __set_size(list, list->size-1);
    return true;
}


bool al_get(ArrayList list, unsigned index, T *output) {
    if(index >= list.size)
        return false;

    *output = list.array[index];
    return true;
}


unsigned al_get_size(ArrayList list) {
    return list.size;
}


bool al_is_empty(ArrayList list) {
    return al_get_size(list) <= 0;
}
