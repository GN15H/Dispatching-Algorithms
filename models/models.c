#include "models.h"
#include <string.h>

Process createProcess(const char *name, int burst, int time, int priority) {
    Process p;
    strcpy(p.name, name);  
    p.burst = burst;
    p.time = time;
    p.priority = priority;
    return p;  
}


ProcessGraph createProcessGraph(Process p, int start) {
    ProcessGraph pg;
    pg.process = p;
    pg.start = start;
    return pg;  
}
