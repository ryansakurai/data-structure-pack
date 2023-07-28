/**
 *  Array implementation of a min heap (priority heap)
 * 
 *  Author: Ryan Sakurai
 */

#include "max_heap.h"

#define MIN_ALLOC 1

void __set_size(MaxHeap *heap, unsigned size) {
    heap->size = size;

    while(size > heap->allocation)
        heap->allocation *= 2;
    while(size <= heap->allocation/4 && heap->allocation/2 >= MIN_ALLOC)
        heap->allocation /= 2;

    heap->array = realloc(heap->array, heap->allocation * sizeof(T));
}

void __swap(MaxHeap *heap, unsigned index_a, unsigned index_b) {
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

void maxh_init(MaxHeap *heap, int (*compare)(T a, T b)) {
    heap->array = malloc(MIN_ALLOC * sizeof(T));
    heap->compare = compare;
    heap->allocation = MIN_ALLOC;
    heap->size = 0;
}

void maxh_destroy(MaxHeap *heap) {
    free(heap->array);
    heap->array = NULL;
    heap->compare = NULL;
    heap->size = 0;
    heap->allocation = 0;
}

void maxh_push(MaxHeap *heap, T data) {
    __set_size(heap, heap->size+1);
    heap->array[heap->size - 1] = data;

    //fix heap
    for(int i = heap->size-1; __parent_idx(i) >= 0 && (*heap->compare)(heap->array[i], heap->array[__parent_idx(i)]) > 0; i = __parent_idx(i))
        __swap(heap->array, i, __parent_idx(i));
}

bool maxh_pop(MaxHeap *heap, T *output) {
    if(maxh_is_empty(*heap))
        return false;

    if(output)
        *output = heap->array[0];
    __swap(heap, 0, heap->size-1);
    __set_size(heap, heap->size-1);

    //fix heap
    for(int i=0; __lchild_idx(i) < heap->size && (*heap->compare)(heap->array[i], heap->array[__lchild_idx(i)]) < 0 || __rchild_idx(i) < heap->size && (*heap->compare)(heap->array[i], heap->array[__get_rchild_idx(i)]) < 0; ) {
        if(__lchild_idx(i) < heap->size && __get_rchild_idx(i) < heap->size) {  //both children exist
            if((*heap->compare)(heap->array[__lchild_idx(i)], heap->array[__get_rchild_idx(i)]) > 0) {
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

bool maxh_get_max(MaxHeap heap, T *output) {
    if(maxh_is_empty(heap))
        return false;

    if(output)
        *output = heap.array[0];
    return true;
}

unsigned maxh_get_size(MaxHeap heap) {
    return heap.size;
}

bool maxh_is_empty(MaxHeap heap) {
    return maxh_get_size(heap) <= 0;
}
