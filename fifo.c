#include <stdio.h>
#include "models/models.h"
#include "parse/parse.h"
#include "plot/process_plot.h"
#ifndef MAX_PROCESS
#define MAX_PROCESS 50
#endif

int max(int x, int y){return x > y ? x : y;}


void fifo(Process* p, int amount){
    int time=p[0].time;
    ProcessGraph pgArr[amount];
    for(int i=0; i<amount; i++){
        ProcessGraph pg;
        pgArr[i]= createProcessGraph(p[i],max(p[i].time, time));
        time+= p[i].burst;
    }
    char str[50];
    sortProcesses(pgArr, amount);
    printProcesses(pgArr, amount);
}

int main(){
    int amount = 0;
    Process processes[MAX_PROCESS];
    amount = readProcesses(processes, amount);
    fifo(processes, amount);
    return 0;
}