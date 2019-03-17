#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
void main()
{
int choice;
do
{
printf("select the option\n");
printf("1.Execute ls command \n");
printf("2.Execute pwd command \n");
printf("3.Execute whoami command \n");
printf("4.Sleep\n");
printf("0.exit");
printf("your choice: ");
scanf("%d",&choice);
switch(choice)
{
case 1:
if (fork())
wait(0);
else
execlp("ls","ls",(char *)NULL);
break;
case 2:
if (fork())
wait(0);
else
execlp ("pwd","pwd",(char *)NULL);
case 3:
if (fork())
wait(0);
else
execlp ("whoami","whoami",(char *)NULL);
break;
case 4:
sleep(1);
break;
case 0:
exit(0);
break;
default:
printf("please enter only between 0 and 3\n");
}
}
while (choice != 0);
}

