#include <stdio.h>
//#include "../models/models.h"
#include "parse.h"
#ifndef LINE_SIZE
#define LINE_SIZE 50
#endif

int readProcesses(Process* p, int amount){
    int i=0;
    char line[LINE_SIZE];
    while (fgets(line, sizeof(line), stdin) != NULL) {
        sscanf(line, "%19s %d %d %d", p[i].name, &p[i].burst, &p[i].time, &p[i].priority);
        i++;
    }
    return i;
}

void printData(Process* processes, int amount){
    for(int i=0; i<amount; i++){
        printf("%s %i %i %i\n", processes[i].name, processes[i].burst, processes[i].time, processes[i].priority);
    }
}

