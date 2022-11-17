#include<stdio.h>
int main()
{
int n,i,qt,count=0,temp,sq=0,bt[10],wt[10],tat[10],rem_bt[10];
//n signifies number of process
//i is for using loops
//qt denotes Quantum Time
//count denotes when one process is completed
//temp and sq are temproray variables
//bt[10] denotes burst time
//wt[10] denotes waiting time
//tat[10] denotes turnaround time
//rem_bt[10] denotes remaining burst time
float awt=0,atat=0;
//awt represents average waiting time
//atat represents average turnaround time
printf("Enter number of process (upto 10) = ");
scanf("%d",&n);
printf("Enter burst time of process\n");
for (i=0;i<n;i++)
{
printf("P%d = ",i+1);
scanf("%d",&bt[i]);
rem_bt[i]=bt[i];
}
printf("Enter quantum time ");
scanf("%d",&qt);
while(1)
{
for (i=0,count=0;i<n;i++)
{
temp=qt;
if(rem_bt[i]==0)
{
count++;
continue;
}
if(rem_bt[i]>qt)//changing the value of remaining burst time
rem_bt[i]=rem_bt[i]-qt;
else
if(rem_bt[i]>=0)//if process is exhausted then setting remaining burst time
{
temp=rem_bt[i];
rem_bt[i]=0;
}
sq=sq+temp; //calculating turnaround time
tat[i]=sq;
}
if(n==count)//breaking the loop when all process are exhausted
break;
}
printf("\nProcess\tBurst Time\tTurnaround Time\tWaiting Time\n");
for(i=0;i<n;i++)
{
wt[i]=tat[i]-bt[i];
awt=awt+wt[i];
atat=atat+tat[i];
printf("\n%d\t%d\t\t%d\t\t%d",i+1,bt[i],tat[i],wt[i]);
}
awt=awt/n;
atat=atat/n;
printf("\nAverage waiting Time = %f\n",awt);
printf("Average turnaround time = %f",atat);
return 0;
}
