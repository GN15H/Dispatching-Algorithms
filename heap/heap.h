#ifndef HEAP_H
#define HEAP_H

#include "../models/models.h"

//int minChildIndexSJF(Process* p, int father);

void copyArr(Process* src, Process* arr, int size);

void heapifyUp(Process* p, int index, int size, int (*comparator)(Process*, int, int));

void heapifyDown(Process* p, int index, int size, int (*comparator)(Process*, int, int), int (*minChild)(Process*,int));

#endif