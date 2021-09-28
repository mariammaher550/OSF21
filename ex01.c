#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <pthread.h>
int N = 1e5+3;

 waitingTime(int *arrivalTime, int *burstTime, int *wt, int *avWaiting, int numberOfProcessors){
     wt[0] = 0;
     *avWaiting = 0;
     for(int i = 1; i < numberOfProcessors; i++)
     {
         wt[i] = burstTime[i - 1]+wt[i - 1];
     }

     for(int i = 1; i < numberOfProcessors; i++)
     {
         wt[i] -=arrivalTime[i];
         *avWaiting += wt[i];
     }

 }
void turnAroundTime(int *wt, int *burstTime, int *TAT, int *avTurnaround, int numberOfProcessors){
     for(int i = 0; i < numberOfProcessors; i++){
         TAT[i] = burstTime[i] + wt[i];
         *avTurnaround += TAT[i];
     }

}

void completionTime(int *arrivalTime, int *burstTime, int *CT, int numberOfProcessors) {
    CT[0] = arrivalTime[0] + burstTime[0];
    for(int i = 1; i < numberOfProcessors; i++ )
    {
        CT[i] = burstTime[i] + CT[i - 1];
    }
}

void print(int* arrivalTime, int* burstTime, int* TAT, int* WT, int* CT, int avWaiting, int avTurnAround, int numberOfProcessors )
{
    printf("The following schedule represent the processes running using FCFS:\n\n");
    printf("Arrival time # burst time  # waiting time # completion time # turnaround time\n");
    for(int i = 0;i < numberOfProcessors; i++){
        printf("%d\t\t",arrivalTime[i]);
        printf("%d\t\t",burstTime[i]);
        printf("%d\t\t",WT[i]);
        printf("%d\t\t",CT[i]);
        printf("%d\t\t\t",TAT[i]);
        printf("\n");
    }
}
int main(){
    int CT[N], TAT[N], WT[N], avTurnAround, avWaiting;
    int numberOfProcessors, arrivalTime[N], burstTime[N];
    printf("Please enter number of processors\n");
    scanf("%d", &numberOfProcessors);
    for(int i = 0; i < numberOfProcessors; i++)
    {
        printf("Process # %d\n", i+1);
        printf("Arrival Time: ");
        scanf("%d", arrivalTime + i);
        printf("\nBurst time: ");
        scanf("%d", burstTime + i );
        printf("\n**********************\n\n");
    }
    //sort
    for(int i = 0; i < numberOfProcessors - 1; i++)
    {
        for(int j = i; j <numberOfProcessors - 1; j++)
        {
            if(arrivalTime[j] > arrivalTime[j + 1])
            {
                int temp = arrivalTime[j];
                arrivalTime[j] = arrivalTime[j + 1];
                arrivalTime[j + 1] = temp;
                temp = burstTime[j];
                burstTime[j] = burstTime[j + 1];
                burstTime[j + 1] = temp;
            }
        }
    }

    printf("%d %d %d %d", arrivalTime[0] , arrivalTime[1] , burstTime[0], burstTime[1]);
    completionTime(arrivalTime, burstTime, CT ,numberOfProcessors);
    waitingTime(arrivalTime, burstTime, WT ,&avWaiting, numberOfProcessors);
    turnAroundTime(WT, burstTime, TAT, &avTurnAround, numberOfProcessors);
    print(arrivalTime, burstTime, TAT, WT, CT, avWaiting, avTurnAround, numberOfProcessors);

}


