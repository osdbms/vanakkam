#include<stdio.h>
int main()
{
int bsize[10], psize[10], bno, pno, flags[10], allocation[10], i, j;
for(i = 0; i < 10; i++)
{
flags[i] = 0;
allocation[i] = -1;
}
printf("FIRST FIT MEMORY ALLOCATION:---\n");
printf("Enter no. of holes: ");
scanf("%d", &bno);
printf("\nEnter size of each hole: ");
for(i = 0; i < bno; i++)
scanf("%d", &bsize[i]);
printf("\nEnter no. of processes: ");
scanf("%d", &pno);
printf("\nEnter size of each process: ");
for(i = 0; i < pno; i++)
scanf("%d", &psize[i]);
for(i = 0; i < pno; i++)
{
for(j = 0; j < bno; j++)
{
if(bsize[j] >= psize[i])
{
allocation[i] = j;
bsize[j]=bsize[j]-psize[i];
flags[i]=1;
break;
}
 }
 if(flags[i]==1)
 printf("\n Process %d is allocated to hole %d size of holes after allocation:
",i+1,allocation[i]+1);
 else
 printf("\n Process %d is not allocated size of holes after allocation: ",i+1);
 for(j = 0; j < bno; j++)
printf(" %d ", bsize[j]);
 }
return 0;
}
