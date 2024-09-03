#include  "process_plot.h"
#include <stdio.h>
#include <string.h>
#ifndef MAX_PROCESS
#define MAX_PROCESS 50
#endif

void clearString(char *str, int size) {
    while (size--) {
        *str++ = '\0';
    }
}

void printProcess(ProcessGraph p, char* str, int size){
    int i=0;
    for(; i<p.process.time;i++) str[i] = ' ';
    
    for(; i<p.start; i++) str[i] = '-';
    
    for(;i<p.start+p.process.burst;i++) str[i] = '*';
    
    printf("%s |%s\n",p.process.name, str);
    
}

void getAverageSystemAndWaiting(ProcessGraph* pArr, int size, double* waiting, double* sys){
    for(int i=0; i<size; i++){
        (*waiting)+=pArr[i].start-pArr[i].process.time;
        (*sys)+=pArr[i].start-pArr[i].process.time+pArr[i].process.burst;
    }
    (*waiting)/=size;
    (*sys)/=size;
}

void sortProcesses(ProcessGraph* pArr, int pArrSize){
    ProcessGraph p; 
    for(int i=0; i<pArrSize; i++){
        for(int j=0; j<pArrSize-1; j++){
            if(strcmp(pArr[j].process.name, pArr[j+1].process.name) < 0){
                p=pArr[j];
                pArr[j]=pArr[j+1];
                pArr[j+1]=p;
            }
        }
    }
    
}

void printProcesses(ProcessGraph* pArr, int pArrSize){
    char str[MAX_PROCESS];
    clearString(str,MAX_PROCESS);
    for(int i=0; i<pArrSize;i++){
        printProcess(pArr[i], str, sizeof(str));
        clearString(str, MAX_PROCESS);
    }
    for(int i=0; i<MAX_PROCESS; i++){
        str[i] = '_';
    }
    printf("%s",str);
    double sys=0;
    double waiting=0;
    getAverageSystemAndWaiting(pArr, pArrSize, &waiting, &sys);
    printf("\nTiempo promedio de espera: %f\nTiempo promedio de sistema: %f", waiting, sys);
}
