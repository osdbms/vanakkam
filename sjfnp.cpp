#include<stdio.h>
#include<string.h>
int main(void) {
char pn[20][20], c[20][20];
 int n,i,j,at[20], bt[20], wt[20],ct[20],tat[20];
 int temp1, temp2, count=0,twt=0;
float sum_wait,sum_turn;
printf("SJF Non-Preemptive----\n");
 printf("Enter number of processes:");
 scanf("%d", &n);
 printf("Enter ProcessNo, ArrivalTime, BurstTime of Process %d:\n",i);
 for(i=0; i<n; i++)
 scanf("%s%d%d",&pn[i],&at[i],&bt[i]);
 for(i=0 ; i<n; i++) {
 for(j=i+1; j<n; j++)
 if(((i==0||count<1)&&(at[i]>at[j]||(at[i]==at[j]&&bt[i]>bt[j])))||(count ==
1 && ct[i-1]>=at[j])||((ct[i-1]>=at[j]&&bt[i]>bt[j]))) {
 temp1 = bt[i];
 temp2 = at[i];
 bt[i] = bt[j];
 at[i] = at[j];
 bt[j] = temp1;
 at[j] = temp2;
 strcpy(c[i],pn[i]);
 strcpy(pn[i],pn[j]);
 strcpy(pn[j],c[i]);
 }
 if(i==0 || count<1)
 ct[i] = at[i] + bt[i];
 else 
 ct[i] = ct[i-1] + bt[i];
 tat[i] = ct[i] - at[i];
wt[i]=tat[i]-bt[i];
 count = 0 ;
 for(j=i+1; j<n; j++)
 if(ct[i]>=at[j])
 count++;
 }
 printf("S.N.\tProcess-Name\tArrival-Time\tBurst-Time\tFinish-Time\tTAT\tWait-Time\n");
 for(i=0; i<n; i++)
 printf("%d\t\t%s\t\t%d\t\t%d\t%d\t\t%d\t\t%d\n",(i+1),pn[i],at[i],bt[i],ct[i],tat[i],wt[i]);
printf("\nGANTT CHART::\n");
for(i=0;i<n;i++){
printf(" p%s\t",pn[i]);
}
printf("\n");
printf("0\t");
for(i=0;i<n;i++){
printf("%d\t",ct[i]);
}
 for(i=0;i<n;i++){
sum_wait += wt[i];
sum_turn += tat[i];
}
printf("\n\t Avg turn around = %f\n\t Avg waiting time = %f\n", (sum_turn/n),
(sum_wait/n));
}

