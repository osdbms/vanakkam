#include <stdio.h>
int wait(int S)
{
while(S<=0);
S--;
return S;
}
int signal(int S)
{
S++;
return S;
}
int main()
{
int n,chopstick[30],p,eat[20],k=0,j=0,i=0,l=0,choice;
printf("Dining Philosopher's Problem----\n");
printf("\nEnter the no. of philosophers : ");
scanf("%d",&n);
printf("\n1) Random selection of philosopher \t 2) User selects the philosopher : ");
scanf("%d",&choice);
if(choice==2)
 {
 printf("\nEnter the philosopher no who must be given the eating chance initially {enter
the ID(0->%d)}: \n\n",n-1);
 scanf("%d",&p);
 }
else
 {
 p=rand() % n;
 printf("\nThe philosopher selected is %d and his id is %d\n\n ",p+1,p);
 } 
i=p;
for( j=0;j<n;j++)
{
chopstick[j]=1;
}
while(i<n)
{
if(chopstick[i]==1&&chopstick[(i+1)%n]==1)
{
chopstick[i]=wait(chopstick[i]);
chopstick[(i+1)%n]=wait(chopstick[(i+1)%n]);
printf("\n %d philosopher(id -> %d) eats!!!!!!!!!",i+1,i);
printf("\n The chopstick matrix after philosopher %d eats \n",i+1);
for(l=0;l<n;l++)
 printf("%d ",chopstick[l]);
printf("\n------------------------------------------------------------------------\n");
eat[k]=i;
k++;
}
i++;
}
i=0;
while(i<p)
{
if(chopstick[i]==1&&chopstick[(i+1)%n]==1)
{
chopstick[i]=wait(chopstick[i]);
chopstick[(i+1)%n]=wait(chopstick[(i+1)%n]);
printf("\n %d philosopher(id -> %d) eats!!!!!!!!!",i+1,i);
printf("\n The chopstick matrix after philosopher %d eats \n",i+1);
for(l=0;l<n;l++)
 printf("%d ",chopstick[l]);
printf("\n-------------------------------------------------------------------------\n");
eat[k]=i;
k++;
}
i++;
}
printf("\n\n\n The philopsopher who can eat at the same time\n");
for(j=0;j<k;j++)
{
printf("\t%d(id -> %d)\n",eat[j]+1,eat[j]);
}
i=p;
printf("\n\n Eating Finished\n");
while(i<n)
{
if(chopstick[i]==0&&chopstick[(i+1)%n]==0)
{
chopstick[i]=signal(chopstick[i]);
chopstick[(i+1)%n]=signal(chopstick[(i+1)%n]);
printf("\n %d philosopher(id -> %d) thinks!!!!!!!!!",i+1,i);
printf("\n The chopstick matrix after philosopher %d thinks \n",i+1);
for(l=0;l<n;l++)
 printf("%d ",chopstick[l]);
printf("\n-------------------------------------------------------------------------\n");
}
i++;
}
i=0;
while(i<p)
{
if(chopstick[i]==0&&chopstick[(i+1)%n]==0)
{
chopstick[i]=signal(chopstick[i]);
chopstick[(i+1)%n]=signal(chopstick[(i+1)%n]);
printf("\n %d philosopher(id -> %d) thinks!!!!!!!!!",i+1,i);
printf("\n The chopstick matrix after philosopher %d thinks \n",i+1);
for(l=0;l<n;l++)
 printf("%d ",chopstick[l]);
printf("\n-------------------------------------------------------------------------\n");
}
i++;
}
return 0;
}
