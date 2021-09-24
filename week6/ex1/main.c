#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Process {
    int number;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
};

void getProcessesFromFile(struct Process processes[10], int* processesCount) {
    FILE *file = fopen("input.csv", "r");
    char *line[255];
    *processesCount = 0;

    while (fgets(line, 255, file)) {
        sscanf(
            line, 
            "%d,%d", 
            &processes[*processesCount].arrivalTime, 
            &processes[*processesCount].burstTime
        );
        processes[*processesCount].number = *processesCount;
        *processesCount = *processesCount+1;
    }
    for (int i = *processesCount; i < 10; i++) {
        processes[i].arrivalTime = 0;
        processes[i].burstTime = 0;
    }
}

void swap(struct Process* one, struct Process* two) {
    struct Process t = *one;
    *one = *two;
    *two = t;
}

void printArray(struct Process array[10], int count) {
    for (int i = 0; i < count; i++) {
        printf(
            "P%d\t%d\t%d\t%d\t%d\t%d\n", 
            array[i].number, 
            array[i].arrivalTime, 
            array[i].burstTime,
            array[i].completionTime,
            array[i].turnaroundTime,
            array[i].waitingTime
        );
    }
}

double computeAverageTAT(struct Process array[10], int count) {
    double average = 0;
    for (int i = 0; i < count; i++) 
        average += array[i].turnaroundTime;
    return average / (double) count;
}
double computeAverageWT(struct Process array[10], int count) {
    double average = 0;
    for (int i = 0; i < count; i++) 
        average += array[i].waitingTime;
    return average / (double) count;
}

void printInfo(struct Process array[10], int count) {
    printf("P#\tAT\tBT\tCT\tTAT\tWT\n");
    printArray(array, count);
    printf(
        "Average TAT = %f\nAverage WT = %f\n", 
        computeAverageTAT(array, count),
        computeAverageWT(array, count)
    );
}

void sortByArrivalTime(struct Process processes[10], int processesCount) {
    for (int i = 0; i < processesCount; i++) 
        for (int k = i; k < processesCount; k++) 
            if (processes[i].arrivalTime > processes[k].arrivalTime) 
                swap(&processes[i], &processes[k]);
}

void sortByBurstTime(struct Process processes[10], int processesCount) {
    for (int i = 0; i < processesCount; i++) 
        for (int k = i; k < processesCount; k++) 
            if (
                (processes[i].burstTime > processes[k].burstTime) && 
                (processes[i].arrivalTime == processes[k].arrivalTime)
            ) { 
                swap(&processes[i], &processes[k]); 
            }
}

void fillProcess(struct Process* process, int* time) {
    process->completionTime = 
        (*time >= process->arrivalTime ? *time : process->arrivalTime) 
        + process->burstTime;
    process->turnaroundTime = process->completionTime - process->arrivalTime;
    process->waitingTime = process->turnaroundTime - process->burstTime;
    *time = process->completionTime;
}

void fillProcessesArray(struct Process processes[10], int processesCount) {
    int time = processes[0].arrivalTime;
    for (int i = 0; i < processesCount; i++) 
        fillProcess(&processes[i], &time);
}

int main() {
    int processesCount;
    struct Process processes[10]; 

    getProcessesFromFile(processes, &processesCount);
    sortByArrivalTime(processes, processesCount);
    // sortByBurstTime(processes, processesCount);
    fillProcessesArray(processes, processesCount);

    printInfo(processes, processesCount);

    return 0;
}
