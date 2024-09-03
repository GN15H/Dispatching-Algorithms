#include "heap.h"

void copyArr(Process* src, Process* arr, int size){for(int i=0; i<size; i++) arr[i] = src[i];}

void heapifyUp(Process* p, int index, int size, int (*comparator)(Process*, int, int)){
    Process aux;
    while(comparator(p, index, size)){
        aux=p[index];
        p[index] = p[(index-1)/2];
        p[(index-1)/2] = aux;
        index = (index-1)/2;
    }
}

void heapifyDown(Process* p, int index, int size, int (*comparator)(Process* p, int index, int size), int (*minChild)(Process*,int)){
    Process aux;
    while(comparator(p,index,size)){
        aux=p[index];
        p[index] = p[minChild(p, index)];
        p[minChild(p,index)] = aux;
        index = minChild(p, index);
    }
}