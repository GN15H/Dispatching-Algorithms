#ifndef MODELS_H
#define MODELS_H

typedef struct{
    char name[20];
    int burst;
    int time;
    int priority;
} Process;

Process createProcess(const char *name, int burst, int time, int priority);

typedef struct{
    Process process;
    int start;
} ProcessGraph;

ProcessGraph createProcessGraph(Process process, int start);


#endif