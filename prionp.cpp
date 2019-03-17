#include<stdio.h>
#include<stdlib.h>
struct job_type
{
char name[10];
float arrival,burst,wait,turnaround;
int priority;
};
typedef struct job_type job;
void readprocess(job* b,int n)
{
int i;
for(i=0;i<n;i++)
{
printf("Enter the process id of the process %d:",i+1);
 scanf("%s",b[i].name);
 printf("Enter arrival time:");
 scanf("%f",&(b[i].arrival));
 printf("Enter burst time:");
 scanf("%f",&(b[i].burst));
 printf("Enter priority:");
 scanf("%d",&(b[i].priority));
}
}
void swap(job* jp,int i,int j)
{
job g;
g=jp[i];
jp[i]=jp[j];
jp[j]=g;
}
int sortcheck(job* jp,int j,int k){
if(k==1)
 if(jp[j].arrival > jp[j+1].arrival)
 return 1;
 else
return 0;
else if(k==2)
 if(jp[j].arrival > jp[j+1].arrival||(jp[j].arrival==jp[j+1].arrival &&jp[j].priority >
jp[j+1].priority))
 return 1;
 else
return 0;
}
void sort(job* jp,int n,int k)
{
int i,j;
job g;
for(i=0;i<n-1;i++)
 for(j=0;j<n-i-1;j++)
 if(sortcheck(jp,j,k))
 swap(jp,j,j+1);
}
void display(job* jp,int n)
{
int i,s;
float sumw,sumt;
sumw=sumt=0;
printf("\nProcess Id Arrival Time Burst Time Priority Waiting Time Turnaround
Time\n");
printf("----------------------------------------------------------------------------------------\n");
for(i=0;i<n;i++){
printf("%10.2s%16.2f%12.2f%10d%17.2f%20.2f\n",jp[i].name,jp[i].arrival,jp[i].burst,jp[
i].priority,jp[i].wait,jp[i].turnaround);
 sumw+=jp[i].wait;
 sumt+=jp[i].turnaround;
}
sumw/=n;sumt/=n;
printf("Average Waiting Time=%14.4f\nAverage Turn-around
Time=%14.4f\n",sumw,sumt);
}
void nonpreempt(job* jp,int n)
{
int i,j=0,small,time[10];
job g;
float s=0;
for(i=1;i<n-1;i++)
 if(jp[j].arrival > jp[i].arrival)
 j=i;
 else if(jp[j].arrival==jp[i].arrival && jp[i].priority < jp[j].priority)
 j=i;
jp[0].wait=0;
jp[0].turnaround=jp[0].burst;
time[0]=jp[0].burst;
for(i=0,s=jp[0].burst;i<n-1;i++){
for(j=i+1,small=i+1;j<n;j++)
 if(jp[j].arrival <=s && jp[j].priority < jp[small].priority)
 small=j;
 else if(jp[j].priority==jp[small].priority&& jp[j].arrival < jp[small].arrival)
 small=j;
 swap(jp,i+1,small);
 jp[i+1].wait=s-jp[i+1].arrival;
jp[i+1].turnaround=jp[i+1].wait + jp[i+1].burst;
 s+=jp[i+1].burst;
 time[i+1]=s;
 }
display(jp,n);
printf("\nGANTT CHART\n\t");
printf("\n\t|");
for(i=0;i<n;i++)
 printf("P%s%4c",jp[i].name,'|');
 printf("\t\n\t0");
 for(i=0;i<n;i++)
 if(time[i]>9)
 printf(" %d",time[i]);
 else
 printf(" %d",time[i]);
}
int main()
{
int ch,n,i;
float min;
job * jp=NULL;
job* cp=NULL;
printf("\nPRIORITY NON-PREEMPTIVE SCHEDULING\n");
printf("\nEnter the number of processes:");
scanf("%d",&n);
jp=(job*)malloc(sizeof(job)*n);
 if(jp)
 readprocess(jp,n);
 ch=1;
if(ch==1) {
 nonpreempt(jp,n);

}
}
