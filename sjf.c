#include "models/models.h"
#include "parse/parse.h"
#include "heap/heap.h"
#include "plot/process_plot.h"
#include <stdio.h>
#include <string.h>

int minChildIndexSJF(Process* p, int father){
    if(p[father*2 +1].burst == p[father*2 +2].burst){
        if(p[father*2 +1].time == p[father*2 +2].time){
            return father*2 + 1;
        }else{
            return p[father*2 + 1].time < p[father*2 + 2].time ? father*2 +1: father*2 +2;
        }
    }
    return p[father*2 + 1].burst < p[father*2 + 2].burst ? father*2 +1: father*2 +2;
}

int heapifyDownComparator(Process* p, int index, int size){
    if(!((index*2 +1) < size || (index*2 + 2) < size)) return 0;

    if(p[index].burst == p[minChildIndexSJF(p, index)].burst){
        if(p[index].time == p[minChildIndexSJF(p, index)].time){
            return strcmp(p[index].name,p[minChildIndexSJF(p,index)].name) > 0;
        }else{
            return p[index].time > p[minChildIndexSJF(p, index)].time;
        }
    }
    return ((index*2 +1) < size || (index*2 + 2) < size) && p[index].burst > p[minChildIndexSJF(p, index)].burst;
}

int heapifyUpComparator(Process* p, int index, int size){
    return index > 0 && p[(index-1)/2].burst > p[index].burst;
}

void addProcesses(const Process* p, Process* heap, int time, int* size, int* pCount, int amount){
    for(int i=*pCount; i<amount; i++){
        if(p[i].time > time) break;
        heap[*size] = p[i];
        (*size)++;
        (*pCount)++;
        heapifyUp(heap,(*size)-1,*size, heapifyUpComparator);
    }
}

void addProcessGraph(ProcessGraph* pg, Process* p, int time, int* pgCount, int size){
    if(size == 0) return;
    pg[*pgCount] = createProcessGraph(p[0],time);
    (*pgCount)++;
}

void popProcess(Process* heap, int* size){
    if((*size) == 0) return;
    heap[0] = heap[(*size)-1];
    (*size)--;
    heapifyDown(heap, 0, *size, heapifyDownComparator, minChildIndexSJF);
}

void sjf(const Process* p, int amount){
    int time = 0;
    int size = 0;
    int auxSize = size;
    int pCount = 0;
    int pgCount = 0;
    Process heap[amount];
    ProcessGraph pg[amount];
    while(amount-pCount){
        auxSize = size;
        addProcesses(p, heap, time, &size, &pCount, amount);
        addProcessGraph(pg,heap,time,&pgCount,size);
        time += size == auxSize ? 1 : heap[0].burst;
        popProcess(heap, &size);
    }
    while(size){
        addProcessGraph(pg,heap,time,&pgCount,size);
        time += heap[0].burst;
        popProcess(heap, &size);
    }
    sortProcesses(pg, amount);
    printProcesses(pg,amount);
}

int main(){
    int amount = 0;
    Process processes[50];
    amount = readProcesses(processes, amount);
    sjf(processes,amount);
    return 0;
}