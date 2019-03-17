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
int sortcheck(job* jp,int j,int k)
{
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
for(i=0;i<n;i++)
{
printf("%10.2s%16.2f%12.2f%10d%17.2f%20.2f\n\n",jp[i].name,jp[i].arrival,jp[i].burst,j
p[i].priority,jp[i].wait,jp[i].turnaround);
 sumw+=jp[i].wait;
 sumt+=jp[i].turnaround;
}
sumw/=n;sumt/=n;
printf("Average Waiting_time=%14.4f\nAverage
TurnAround_Time=%14.4f\n",sumw,sumt);
}
int chk(int* w,int n)
{
int i;
for(i=0;i<n;i++)
 if(w[i]!=0)
 return 1;
return 0;
}
void preempt(job* jp,int n)
{
int i,j=0,small,cur,time[2][30],k=0;
int *w =NULL;
w=(int*)malloc(sizeof(int)*n);
if(!w) return;
float s=0;
sort(jp,n,2);
for(i=0,small=0;i<n;i++)
 {
w[i]=jp[i].burst;
 if(jp[i].priority >jp[small].priority)
 small=i;
 }
cur=0;i=small;
while(chk(w,n))
 {
time[0][k]=cur;
 for(j=cur+1,small=cur;j<n;j++)
 if(w[j]!=0)
 if(jp[j].arrival <= (s + w[cur]) && jp[j].priority < jp[cur].priority)
 {
small=j;
 break;
 }
 if(small==cur)
 {
s+=w[cur];
 w[cur]=0;
 jp[cur].turnaround=s-jp[cur].arrival;
 for(j=(cur+1)%n,small=i;j!=cur;j=(j+1)%n)
 if(w[j]!=0)
 if(jp[j].arrival<=s && jp[j].priority <=jp[small].priority)
 small=j;
 cur=small;
 }
 else
 {
s=s+jp[small].arrival-jp[cur].arrival;
 w[cur]=w[cur]-jp[small].arrival + jp[cur].arrival;
 cur=small;
 }
 time[1][k++]=s;
 }
 for(i=0;i<n;i++)
 jp[i].wait=jp[i].turnaround-jp[i].burst;
 free(w);
 display(jp,n);
 printf("\nGANTT CHART\n\t");
 for(i=0;i<k;i++)
 printf("%4s%4c",jp[time[0][i]].name,'|');
 printf("\n\t");
 printf("\n\t0");
 for(i=0;i<k;i++)
 if(time[1][i]>9)
 printf(" %d",time[1][i]);
 else
 printf(" %d",time[1][i]);
}
int main()
{
int ch,n,i;
float min;
job * jp=NULL;
job* cp=NULL;
printf("PRIORITY-PREEMPTIVE SCHEDULING\n");
printf("\nEnter the number of processes:");
scanf("%d",&n);
jp=(job*)malloc(sizeof(job)*n);
 if(jp)
 readprocess(jp,n);
 ch=2;
 if(ch==2)
 {
 preempt(jp,n);
 }
}
