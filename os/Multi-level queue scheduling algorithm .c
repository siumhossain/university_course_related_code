 #include <stdio.h>
#include <stdlib.h>
 int main()
{
//initial value
int p[20],bt[20], su[20], wt[20],tat[20],i, k, n, temp;
float wtavg, tatavg;

printf("arrival time is '0' is predefined\n");

//define number of process
printf("Enter the number of processes --- ");
scanf("%d",&n);

//geting brust time && sytem user process number 0 or 1
for(i=0;i<n;i++)
{
p[i] = i;
printf("Enter the Burst Time of Process %d --- ", i);
scanf("%d",&bt[i]);
printf("System/User Process (0/1) ? --- ");
scanf("%d", &su[i]);
}

//sorting process,brust_time by sys/user process 

for(i=0;i<n;i++){
    for(k=i+1;k<n;k++){
        if(su[i] > su[k])
        {
        temp=p[i];
        p[i]=p[k];
        p[k]=temp;
        temp=bt[i];
        bt[i]=bt[k];
        bt[k]=temp;
        temp=su[i];
        su[i]=su[k];
        su[k]=temp;
        }
    }
}
//define waiting avg as 0 && also turn_around_time
wtavg = wt[0] = 0;
tatavg = tat[0] = bt[0];

//storing waiting time && turn_around_time && wating avg time && avg turn_around_time
for(i=1;i<n;i++)
{
wt[i] = wt[i-1] + bt[i-1];
tat[i] = tat[i-1] + bt[i];
wtavg = wtavg + wt[i];
tatavg = tatavg + tat[i];
}
//finally printing value 
printf("\nPROCESS\t\t SYSTEM/USER PROCESS \tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
for(i=0;i<n;i++){
printf("\n%d \t\t %d \t\t\t %d \t\t\t %d \t\t %d ",p[i],su[i],bt[i],wt[i],tat[i]);
}
printf("\nAverage Waiting Time is --- %f",wtavg/n);
printf("\nAverage Turnaround Time is --- %f",tatavg/n);


}