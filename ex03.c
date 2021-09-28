

#include <stdio.h>
const int N=1000,MAX=1e9;
int arrivalTime[1000],brustTime[1000],brustTemp[1000],numberOfProcessors; 
long long int waitingTime[1000],completionTime[1000],turnOver[1000];
void roundRobin(int x){
    int doneC=0,lastT=0; 
    while(doneC<numberOfProcessors){
        int minimumTime=MAX; 
        for(int i=0;i<numberOfProcessors;i++){
            if(!brustTemp[i])
                continue;
            if(arrivalTime[i]<minimumTime)
                minimumTime=arrivalTime[i];
        }
        if(minimumTime> lastT)
            lastT= minimumTime;
     //robin basic
        for(int i=0;i<numberOfProcessors;i++){
            if(!brustTemp[i])
                continue;
            if(arrivalTime[i]>lastT)
                continue;
            if(brustTemp[i]<=x){
                lastT+=brustTemp[i];
                brustTemp[i]=0;
                completionTime[i]= lastT;
                doneC++;
            }
            else{
                lastT+=x;
                brustTemp[i]-=x;
            }
        }
    }

}
void calculateWait(){
    for(int i=0;i<numberOfProcessors;i++){
        waitingTime[i]= completionTime[i]- brustTime[i]-arrivalTime[i];
    }
}

void calculateTurnaround(){
    for(int i=0;i<numberOfProcessors;i++){
        turnOver[i]= brustTime[i]+waitingTime[i];
    }
}
int getAverageTurnaround(){
    long long int sum=0;
    for(int i=0;i<numberOfProcessors;i++){
        sum+= turnOver[i];
    }
    sum/=numberOfProcessors;
    return (int)sum;
}
int getAverageWaiting(){
    long long int sum=0;
    for(int i=0;i<numberOfProcessors;i++){
        sum+= waitingTime[i];
    }
    sum/=numberOfProcessors;
    return (int)sum;
}
void print(){
    printf("The following schedule represents the processes running using Round Robin algorithm:\n\n");
    printf("Arrival time # burst time  # waiting time # completion time # turnaround time\n");
    for(int i=0;i<numberOfProcessors;i++){
        printf("%d\t\t",arrivalTime[i]);
        printf("%d\t\t",brustTime[i]);
        printf("%d\t\t",waitingTime[i]);
        printf("%d\t\t",completionTime[i]);
        printf("%d\t\t\t",turnOver[i]);
        printf("\n");
    }
    printf("Average turn around time: %d\n",(getAverageTurnaround()));
    printf("Average waiting time: %d\n",(getAverageWaiting()));
}
int main(){
    int qt;
    printf("This code will run n processes, using round robin algorithm:\nPlease enter QT: ");
    scanf("%d",&qt);

    printf("\nplease enter the number of processes\n");
    scanf("%d",&numberOfProcessors);
    for(int i=0;i<numberOfProcessors;i++){
        printf("Process # %d:\n",i+1);
        printf("Arrival time: ");
        scanf("%d",arrivalTime+i);
        printf("\nBurst time: ");
        scanf("%d",brustTime+i);
        brustTemp[i]=brustTime[i];
        printf("\n**********************\n\n");
    }
    roundRobin(qt);
    calculateWait();
    calculateTurnaround();
    print();
    return 0;
}
