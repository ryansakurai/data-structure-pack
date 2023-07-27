/**
 *  Array implementation of a heap (priority heap)
 * 
 *  Author: Ryan Sakurai
 */

#include "heap.h"

#define MIN_ALLOC 1

void __set_size(Heap *heap, unsigned size) {
    heap->size = size;

    while(size > heap->allocation)
        heap->allocation *= 2;
    while(size <= heap->allocation/4 && heap->allocation/2 >= MIN_ALLOC)
        heap->allocation /= 2;

    heap->array = realloc(heap->array, heap->allocation * sizeof(T));
}

void __swap(Heap *heap, unsigned index_a, unsigned index_b) {
    T temp = heap->array[index_a];
    heap->array[index_a] = heap->array[index_b];
    heap->array[index_b] = temp;
}

unsigned __parent_idx(unsigned index) {
    return (index-1)/2;
}

unsigned __lchild_idx(unsigned index) {
    return index*2+1;
}

unsigned __rchild_idx(unsigned index) {
    return index*2+2;
}

void h_init(Heap *heap) {
    heap->array = malloc(MIN_ALLOC * sizeof(T));
    heap->allocation = MIN_ALLOC;
    heap->size = 0;
}

void h_destroy(Heap *heap) {
    free(heap->array);
    heap->array = NULL;
    heap->size = 0;
    heap->allocation = 0;
}

void h_push(Heap *heap, T data) {
    __set_size(heap, heap->size + 1);
    heap->array[heap->size - 1] = data;

    //fix heap
    for(int i = heap->size-1; __parent_idx(i) >= 0 && heap->array[i] < heap->array[__parent_idx(i)]; i = __parent_idx(i) )
        __swap(heap->array, i, __parent_idx(i));
}


bool h_pop(Heap *heap, T *output) {
    if(h_is_empty(*heap))
        return false;

    if(output)
        *output = heap->array[0];
    __swap(heap, 0, heap->size-1);
    __set_size(heap, heap->size-1);

    //fix heap
    for(int i=0; __lchild_idx(i) < heap->size && heap->array[i] > heap->array[__lchild_idx(i)] || __get_rchild_idx(i) < heap->size && heap->array[i] > heap->array[__get_rchild_idx(i)]; ) {
        if(__lchild_idx(i) < heap->size && __get_rchild_idx(i) < heap->size) {  //both children exist
            if(heap->array[__lchild_idx(i)] < heap->array[__get_rchild_idx(i)] ) {
                swap(i, __lchild_idx(i));
                i = __lchild_idx(i);
            }
            else {
                swap(i , __rchild_idx(i));
                i = __rchild_idx(i);
            }
        }
        else if(__lchild_idx(i) < heap->size) { //only left child exists
            swap(i, __lchild_idx(i));
            i = __lchild_idx(i);
        }
        else {  //only right child exists
            swap(i, __rchild_idx(i));
            i = __rchild_idx(i);
        }
    }

    return true;
}


bool h_get_min(Heap heap, T *output) {
    if(h_is_empty(heap))
        return false;

    if(output)
        *output = heap.array[0];
    return true;
}


unsigned h_get_size(Heap heap) {
    return heap.size;
}


bool h_is_empty(Heap heap) {
    return h_get_size(heap) <= 0;
}
