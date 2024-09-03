#ifndef PROCESS_PLOT_H
#define PROCESS_PLOT_H

#include "../models/models.h"

void printProcess(ProcessGraph p, char* str, int size);
void printProcesses(ProcessGraph* pArr, int pArrSize);
void sortProcesses(ProcessGraph* pArr, int pArrSize);
#endif