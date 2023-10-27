/**
 *  Array implementation of an ordered list
 * 
 *  Author: Ryan Sakurai
 */

#include "array_ordered_list.h"

#define MIN_ALLOC 1

void __set_size(ArrayOrderedList *list, unsigned size) {
    list->size = size;

    while(size > list->allocation)
        list->allocation *= 2;
    while(size <= list->allocation/4 && list->allocation/2 >= MIN_ALLOC)
        list->allocation /= 2;

    list->array = realloc(list->array, list->allocation * sizeof(T));
}

void __swap(ArrayOrderedList *list, unsigned index_a, unsigned index_b) {
    T temp = list->array[index_a];
    list->array[index_a] = list->array[index_b];
    list->array[index_b] = temp;
}

void aol_init(ArrayOrderedList *list, int (*compare)(T a, T b)) {
    list->array = malloc(MIN_ALLOC * sizeof(T));
    list->allocation = MIN_ALLOC;
    list->size = 0;
    list->compare = compare;
}

void aol_destroy(ArrayOrderedList *list) {
    free(list->array);
    list->array = NULL;
    list->size = 0;
    list->allocation = 0;
    list->compare = NULL;
}

void aol_push(ArrayOrderedList *list, T data) {
    // find new item's index
    int index;
    for(index = 0; index < list->size && (*list->compare)(data, list->array[index]) > 0; index++);

    __set_size(list, list->size+1);

    // open space for new item
    for(int i = index+1; i < list->size; i++)
        list->array[i] = list->array[i-1];

    list->array[index] = data;
}

bool aol_remove(ArrayOrderedList *list, unsigned index) {
    if(index >= list->size)
        return false;

    for(int i=index; i+1 < list->size; i++)
        list->array[i] = list->array[i+1];
    __set_size(list, list->size-1);
    return true;
}

bool aol_get(ArrayOrderedList list, unsigned index, T *output) {
    if(index >= list.size)
        return false;

    *output = list.array[index];
    return true;
}

unsigned aol_get_size(ArrayOrderedList list) {
    return list.size;
}

bool aol_is_empty(ArrayOrderedList list) {
    return aol_get_size(list) <= 0;
}
