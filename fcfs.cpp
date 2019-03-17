#include<stdio.h>
int main()
{
int i ,n, start[10], finish[10], burst[10], arrival[10], wait[10], turn[10];
float sum_wait = 0,
sum_turn = 0;
printf("FCFS-----\n");
printf("Enter the number of jobs ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter the %d th burst time and arrival time",i);
scanf("%d%d",&burst[i], &arrival[i]);
}
printf("\n\tjob\tburst\tAT\tstart\tfinish\t WT\t TAT");
start[0] = arrival[0];
for(i=0;i<n;i++)
{
start[i+1] = finish[i] = start[i]+burst[i] ;
wait[i]= start[i]-arrival[i] ;
turn[i]=finish[i]-arrival[i];
printf("\n\t %d\t %d\t %d\t %d\t %d\t %d\t %d ", i, burst[i], arrival[i],
start[i],finish[i],wait[i], turn[i]);
}
printf("\nGANTT CHART::\n");
for(i=0;i<n;i++)
{
printf(" p%d\t",i);
}
printf("\n");
for(i=0;i<n;i++)
{
printf("%d\t",start[i]);
}
printf("%d",finish[n-1]);
for(i=0;i<n;i++)
{
sum_wait += wait[i];
sum_turn += turn[i];
}
printf("\n\t Avg turn around = %f\n\t Avg waiting time = %f\n", (sum_turn/n),
(sum_wait/n));
}

